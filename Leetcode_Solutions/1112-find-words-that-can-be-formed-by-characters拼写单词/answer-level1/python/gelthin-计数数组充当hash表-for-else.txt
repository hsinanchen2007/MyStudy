### 解题思路
hash 表有很多相似题目。
这一题由于需要统计数量，无法使用 bitmap 等方法
如果有题目只需要统计 0/1  值的话，完全可以使用 bitmap 方法。

### 官方题解提到了 Python 的for ... else 结构
[我个人的一点分析](https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters/solution/pin-xie-dan-ci-by-leetcode-solution/290425)

不过我看 《流畅的 python》 上面说不推荐这样写，这样写容易混乱。
python for 循环有一个大问题就是我们无法通过判断循环变量 i 来判断是否提前终止了，例如：
```python3
for i in range(10): 
    if i==9: 
        break   
```

和
 
``` python3
for i in range(10): 
    pass
```

最终变量 i 的值都会停在 9， 而不是第一个为 9， 第二个为 10. 需要额外引进一个 flag 变量来辅助判断。 例如：

```python3
flag = True
for i in range(10): 
    if i==9: 
        flag=False 
        break
```

然后判断 flag 是否为 False 来判断是否提前终止。

python 一定程度上为了弥补这一问题， 引入了 for .. else 结构。
这个 for ... else... 中的 else 表示若循环有效结束，而不是提前终止，就执行 else 后面的语句，若提前终止，就不执行。这个 ‘else’ 和 if..else 中的else 语义不一样。或许用 then 更合适，但 python 之父不愿意再新定义一个关键字 then，就复用了这个 else 

另外，这里 for 语句中的变量 i 非常特殊，例如下面的语句 

``` python3
for i in range(5): 
    i += 1 
    print(i) # 输出 [1,2,3,4,5]
```
### [python3 pythonic 的写法](https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters/solution/tong-ji-python3-by-smoon1989/)：

collections.Counter() 可以直接输出一个 dict, 统计 word 中每个 char 和其出现的次数 
``` python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        ans = 0
        cnt = collections.Counter(chars)
        for w in words:
            c = collections.Counter(w)
            if all([c[i] <= cnt[i] for i in c]):
                ans += len(w)
        return ans
```





#### 代码注意：
+ 注意到 python  for 循环无法通过循环变量 i 来判断循环提前终止还是没有，需要使用 1个 flag 变量，或者使用 count 变量来统计。
+ 注意到 break 语句后面的语句无法执行。千万不要把关键语句写到了 break 后面。




### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        hash_s = [0]*26
        for x in chars:
            hash_s[ord(x)-ord('a')] += 1
        result = 0
        for word in words:
            tmp = hash_s.copy()
            flag = True
            for x in word:
                if tmp[ord(x)-ord('a')]<1:
                    flag = False ## 放在 break 后面的语句无法执行
                    break
                else:
                    tmp[ord(x)-ord('a')] -= 1
            if flag == True:
                result += len(word)
        return result

```