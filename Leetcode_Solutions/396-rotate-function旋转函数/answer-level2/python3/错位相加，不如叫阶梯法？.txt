## 成绩（2019-07-12）
执行用时 :72 ms, 在所有 Python3 提交中击败了70.69%的用户

内存消耗 :15.2 MB, 在所有 Python3 提交中击败了8.33%的用户

空间换时间，应该有优化余地

## 思路

### 暴力解法

刚开始的初始情况就是 `j*A[j-0]` 求和，然后第二轮就是 `j*A[j-1]` 求和，得益于python列表的下标支持负数，所以这样的逻辑简洁明了，但是也多了很多不必要的计算，时间复杂度应该是：$O（n^2）$。

尽管已经用了列表推导式一行解决，但还是会超出时间限制。
```python
class Solution:
    def maxRotateFunction(self, A: List[int]) -> int:
        l = len(A)
        if l:
            return max([sum([j*A[j-i] for j in range(l)]) for i in range(l)])
        else:
            return 0
```

### 所谓的阶梯法

和这位大哥的思路相同：[whererun](https://leetcode-cn.com/problems/rotate-function/comments/98129)，不过我是做完才看的评论发现的

第一轮是：

0. **4**
1. **3，3**
2. **2，2，2**
3. **6，6，6，6**

第二轮是：

0. **6**
1. **4，4**
2. **3，3，3**
3. **2，2，2，2**

第三轮是：

0. **2**
1. **6，6**
2. **4，4，4**
3. **3，3，3，3**

第四轮是：

0. **3**
1. **2，2**
2. **6，6，6**
3. **4，4，4，4**

多写了一个是为了方便观察走势，可以看到每轮变化就是前三行的向下走一层，最下一层的走到最上一层。

用数字表达就是每轮变换要加上$n-1$个数的和，再减去剩下一个数的$n-1$倍

在整个变换过程中，只需要计算好初始情况，第一次变换（得到第二轮结果）就是减去列表最后一个数的$n-1$倍，然后加上前$n-1$个数的和

同理，第$i$次变换（得到第$i+1$轮结果）就是在上一轮的基础上减去倒数第$i$个数的$n-1$倍，然后加上其他数的和

```python
class Solution:
    def maxRotateFunction(self, A: List[int]) -> int:
        l, total = len(A), sum(A)
        if l:
            s = [total - A[i] for i in range(l-1, -1, -1)]
            begin = sum([i*A[i] for i in range(l)])
            ans = begin
            for i in range(l-1, -1, -1):
                begin += (-(l-1)*A[i] + s[l-1-i])
                ans = max(ans, begin)
            return ans
        else:
            return 0
```
