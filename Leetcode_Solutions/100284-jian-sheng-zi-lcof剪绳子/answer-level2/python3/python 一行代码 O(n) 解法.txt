### 解题思路

一行代码不好看。（代码在最后） 另外还有 [一行代码 O(1) 解法](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/python-yi-ju-hua-o1-jie-fa-by-amir-6/)
所以还有多行版本：

```python
class Solution:
    def cuttingRope(self, n: int) -> int:
        ans = 0
        for m in range(2, n+1):
            x = n // m
            r = n % m
            m = x ** (i-r) * (x+1) ** (r)
            if ans < m:
                ans = m
            else: 
                break
        return ans
```
这里的思路是尽量变让每段绳子长度相接近，遍历从切成 2 段到 n 段。时间复杂度 O(n)

每次迭代，算 x = n//m 就是所有绳子中最短的绳子有多长。 r = n % m，是 n 除以 m 的余数，余下长度，分给 r 段绳子，让他们的长度变为 x + 1

### 代码

```python
class Solution:
    def cuttingRope(self, n: int) -> int:
        return max([(n//m) ** (m-n%m) * ((n//m)+1) ** (n%m) for m in range(2, n+1)])
```


欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)