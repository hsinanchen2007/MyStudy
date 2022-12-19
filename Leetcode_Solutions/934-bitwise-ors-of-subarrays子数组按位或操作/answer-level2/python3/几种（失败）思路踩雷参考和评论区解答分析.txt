## 几种（失败）思路踩雷参考和评论区解答分析
--------
最近刚好在学<计算机组成原理>，对位或操作还挺熟悉，Python中的`|`就是位或的运算符。它会自动补全较小数的前几个有效位，比如`1|4`就等价于`001|100`结果是5。

#### 尝试1
这道题最初我是用二重循环来做:
```Python
class Solution:
    def subarrayBitwiseORs(self, A: List[int]) -> int:
        n, s = len(A), {A[0]}
        for i in range(n):
            tmp = A[i]
            s.add(tmp)
            for j in range(i+1, n):
                tmp |= A[j]
                s.add(tmp)
        return len(s)
```
但是不幸超出时间限制:[超出时间限制的测试用例](https://leetcode-cn.com/submissions/detail/19041402/)

#### 尝试2
分析原因肯定是因为二重循环很慢导致的。于是我先在这个结构的基础上进行改进，考虑到`s.add()`相当于在每次循环中判断一下集合中是否有重复值，这样的做法不经济，于是将`s`由集合换成列表:

```Python
class Solution:
    def subarrayBitwiseORs(self, A: List[int]) -> int:
        n, s = len(A), []
        for i in range(n):
            tmp = A[i]
            s.append(tmp)
            for j in range(i+1, n):
                tmp |= A[j]
                s.append(tmp)
        return len(set(s))
```
依然是[超出时间限制](https://leetcode-cn.com/submissions/detail/19044635/)

#### 尝试3

思考了一下用列表推导式，实在是太烧脑。首先二重循环是无疑的，但不一定非要是显式的二重for循环，之前用了一个临时量`tmp`的做法可以在以前的基础上进行后续的位或运算，已经是减少了计算量。但如果是列表推导式的话那么，它本身没有运行中的存储，也不能对外部变量赋值(据我了解不能)。所以如果非要用列表推导式的话....
```Python
class Solution:
    def subarrayBitwiseORs(self, A: List[int]) -> int:
        n = len(A)
        s = [A[i:j] for i in range(n) for j in range(i+1, n+1)]
        s = [eval("|".join([str(j) for j in i])) for i in s]
        return len(set(s))
```
仍旧是[超出时间限制](https://leetcode-cn.com/submissions/detail/19045489/)

这个原因就更明显了，肯定是因为`eval`很慢。

我觉得我再这么尝试下去我的通过率数据就不能看了.....于是最后参考了评论区的做法。

#### 评论区参考
来自leetcode-cn.com @Peter
```Python
class Solution:
    def subarrayBitwiseORs(self, A):
        cur = set()
        res = set()
        for a in A:
            cur = {n | a for n in cur} | {a}
            res |= cur
        return len(res)
```
这是一种空间换时间的做法，一个`cur`集合储存上一次循环的位或结果集合，将这些集合和当前循环的元素进行位或运算，在补充上当前元素。然后一个`res`和`cur`取并集。
为什么要有一个`cur`而不直接用`res`呢？或者为什么要用两个集合而不是一个集合呢？

考虑`[1，2，4]`这个测试用例:

第一轮循环时，`a=1`,`cur={1}`,`res={1}`

第二轮循环时，`a=2`,`cur = {1|2}|{2} = {2,3}`, `res={1,2,3}`

第三轮循环时，`a=4`,`cur={2|4, 3|4}|{4} = {4, 6, 7}`,`res={1,2,3,4,6,7}`

那么显然直接返回`cur`的长度是不可能的，直接返回`cur`和原始输入`A`的并集也是不可以的，因为漏掉了3。对于我能考虑到替换`res`的两种方法，都会导致测试不通过，所以`res`这个集合的存在是有必要的。
