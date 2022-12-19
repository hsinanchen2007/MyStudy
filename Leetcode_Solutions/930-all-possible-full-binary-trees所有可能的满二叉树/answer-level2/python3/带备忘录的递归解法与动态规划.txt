一 算法分析与设计
1 带备忘录的递归解法
二叉树中度数为0的结点个数（n0）比度数为2(n2)的结点个数多1，即n0 = 1 + n2。满二叉树不含度数为1的结点，故其结点个数为1+2*n2，为奇数。故当N为偶数时，可直接返回[]。
当N=0时，结果为[]。当N=1时，结果为[TreeNode(0)]。
以FBT(N)表示所有由N个结点构成的满二叉树的列表。当N>=3时，可考虑如下的递归策略，对于所有i<N（且i为奇数），所有树的左子结点来自FBT(i),右子结点来自FBT(N-i-1)。为避免重复计算，用字典记录已经计算的结果。
2 动态规划
N为偶数，直接返回[]
N为奇数时：
（1）状态
结点个数
（2）初始边界
N=1,dp[1] = [TreeNode(0)]
（3）状态转移方程
dp[N]为由所有小于N的奇数i中的结果dp[i]作为其左结点，dp[N-i-1]中的结果作为其右结点得到的树。
二 算法实现
带备忘录的递归算法
```python3 []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def allPossibleFBT(self, N: int) -> List[TreeNode]:
        memo = {0: [], 1: [TreeNode(0)]}
        
        def get_FBT(n):
            if n in memo:
                return memo[n]
            res = []
            for x in range(n):
                y = n - 1 - x
                for left in get_FBT(x):
                    for right in get_FBT(y):
                        p = TreeNode(0)
                        p.left = left
                        p.right = right
                        res.append(p)
            memo[n] = res
            return res

        get_FBT(N)
        return memo[N]
```
动态规划
```python3 []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def allPossibleFBT(self, N: int) -> List[TreeNode]:
        if N & 1 == 0:
           return []
        dp = [[] for _ in range(N+1)]
        dp[1] = [TreeNode(0)]
        for j in range(3, N+1, 2):
           res = []
           for x in range(1, j, 2):
               y = j - 1 - x
               for left in dp[x]:
                   for right in dp[y]:
                       p = TreeNode(0)
                       p.left = left
                       p.right = right
                       res.append(p)
           dp[j] = res
        return dp[N]

             
        ## simple edtion but hard to understand
        # if N & 1 == 0:
        #     return []
        # n = (N >> 1) + 1
        # dp = [[] for _ in range(n + 1)]
        # dp[1] = [TreeNode(0)]
        # for j in range(2, n + 1):
        #     res = []
        #     for x in range(1, j):
        #         y = j - x
        #         for left in dp[x]:
        #             for right in dp[y]:
        #                 p = TreeNode(0)
        #                 p.left = left
        #                 p.right = right
        #                 res.append(p)
        #     dp[j] = res
        # return dp[-1]
```



