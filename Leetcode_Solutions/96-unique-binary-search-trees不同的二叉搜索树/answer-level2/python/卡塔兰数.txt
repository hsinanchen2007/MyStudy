### 解题思路
递推公式: f(n) = sum(f(i-1)*f(n-i)), i in [1,n]
f(1-1)*f(n-1)就代表以第一个数为根节点形成的二叉搜索数个数
f(0)是代表左边的树为空树, f(n-1)代表右边是有n-1个节点的二叉树
官方题解的推导更细致
设F(i,n)代表是以第i个节点为根节点, 总共有n个节点可以形成的二叉树个数. G(n)代表n个节点的二叉树个数
最后推倒的结果仍符合卡特兰数
所以二叉搜索树是和普通二叉树个数是一样的

其公式如图
![image.png](https://pic.leetcode-cn.com/d7c2defd6a3e1ebe88b58ac5b13f210ef56cec3468d28c1e2918408a4a72ce01-image.png)


### 代码

```python3
class Solution:
    def numTrees(self, n: int) -> int:
        def solve(n):
            if n==0 or n==1: return 1
            if n in memo:
                return memo[n]
            tmp = 0
            for i in range(1, n+1):
                tmp += solve(i-1)*solve(n-i)
            memo[n] = tmp
            return memo[n]
        memo = {}
        return solve(n)
```