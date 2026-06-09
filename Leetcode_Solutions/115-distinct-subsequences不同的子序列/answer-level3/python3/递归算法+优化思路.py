### 解题思路
起初我想到的是递归算法，针对`S`和`T`的字符一个一个进行比较，然后用题目中的两个示例编写单元测试进行验证，基本没问题。但是提交代码后发现遇到一些复杂参数时，执行效率和空间资源利用率并没有达到很好的水平，所以进行了一系列的优化。

优化思路：

- 缓存计算结果：避免重复计算，快速得到计算过的结果
- 提高有效计算的密度：设置判断条件，忽略最终失败的情况，避免算法空跑
- 缓存空间优化：用偏移量拼接作为Key

#### 缓存计算结果
每一次`return`前将计算结果存入cache，Key的设置与`S`和`T`强相关（最初使用`S.T`的形式作为Key）

#### 提高有效计算密度
判断边界，忽略可能存在无效计算的情况。

在最初的代码中进行逐个比较`S`和`T`的字符时，`T[0]`字符可能会出现在`S`中相当末尾的位置，而前面的每一个字符比较都会进行一次入栈，容易造成帧栈数量过多，内存资源消耗较多。优化方式是：在`S`中查找`T[0]`字符所在的位置(`s_start`)，忽略`S`头部的无效字符，直接跳到`s_start`位置开始比对。如果`S`中未找到`T[0]`，则直接返回`0`

#### 缓存空间优化
最初代码使用`S`和`T`截取后的子串作为参数进行下一轮递归，缓存的Key格式为`S.T`，中间以`.`分隔。但是这种方式在大字符串的初始计算条件下，容易造成缓存Key过长，内存消耗较大的问题。于是优化方式是，在递归方法`_num_distinct`设置了两个偏移量参数，使用原始的字符串参数+位置偏移量进行计算，同时，缓存的Key改为`s_offset.t_offset`，降低了Key长度。执行结果是内存消耗由最初的`29.3 MB`降为了`13.3 MB`

### 总结
大概考虑了1天左右的时间吧。做出来后看了下题解，发现解题方法和思路有很多，不过我没办法一一都用代码实现。软件工程的意义是付出合理的代价取得满意的成果，对我来说得到双90的结果已经很OK了。当然，挖掘解题思路和专注极致优化的做法同样值得敬佩。

### 代码

```python3
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        return self._num_distinct(s, 0, t, 0, {})

    def _num_distinct(self, s: str, s_offset: int, t: str, t_offset: int, cache: dict) -> int:
        key = '{}.{}'.format(s_offset, t_offset)

        cached = cache.get(key)
        if cached:
            return cached
        if cached == 0:
            return 0

        if t_offset == len(t):
            return 1

        if s_offset == len(s):
            return 0

        s_start = s.find(t[t_offset], s_offset)
        if s_start == -1:
            cache[key] = 0
            return 0
        else:
            count = self._num_distinct(s, s_start + 1, t, t_offset + 1, cache) + \
                    self._num_distinct(s, s_start + 1, t, t_offset, cache)
            cache[key] = count
            return count
```

```python3

class MyTestCase(unittest.TestCase):

    def test1(self):
        s = 'rabbbit'
        t = 'rabbit'

        solution = Solution()
        result = solution.numDistinct(s, t)
        self.assertEqual(3, result)

    def test2(self):
        s = 'babgbag'
        t = 'bag'

        solution = Solution()
        result = solution.numDistinct(s, t)
        self.assertEqual(5, result)

    def test3(self):
        s = 'aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe'
        t = 'bddabdcae'

        solution = Solution()
        result = solution.numDistinct(s, t)
        self.assertEqual(10582116, result)

    def test4(self):
        s = 'xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo'
        t = 'rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys'

        solution = Solution()
        result = solution.numDistinct(s, t)
        self.assertEqual(543744000, result)
```