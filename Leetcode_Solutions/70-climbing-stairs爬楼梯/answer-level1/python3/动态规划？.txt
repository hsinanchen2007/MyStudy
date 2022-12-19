### 解题思路
此处撰写解题思路

学习新得：

还是要注意，类函数传递的问题。
以及python3的新的属性，dict 中key in dict确认是否有这个键


### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        # 子问题递归
        self.L = {}
        # 注意退出条件
        return self.dg(self.L, n)
    def dg(self, L, n):
        if n == 1:
            return 1
        if n == 2:
            return 2
        if n in L:
            
            return L[n]
        res = self.dg(L,n-1) + self.dg(L ,n-2)
        L[n] = res
        return res
```