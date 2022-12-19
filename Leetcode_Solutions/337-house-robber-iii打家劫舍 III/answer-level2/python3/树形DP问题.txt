树形DP的做法：DP的集合一般均设置为以某个节点为根的所有方案，属性根据题目来定，实现方法一般在dfs中自动进行dp,这种树形DP常用记忆化搜索的方式来做，即递归过程中算过的状态存储在dp数组中，避免重复的状态计算，这是自上而下递归动态规划一定要避免的，这道题的树是用链表的方式存储的不是数组，因此使用dict类型作为记忆化搜索中的dp数组。
为什么可以用记忆化搜索：动态规划中的状态必须有拓扑结构不能有环，这道题是树显然没环因此树形DP基本都能使用这种方法解决
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def rob(self, root: TreeNode) -> int:
        dp = {}
        if root is None:
            return 0
        def dfs(node,state):
            if node in dp.keys():
                if dp[node][state] != -1:
                    return dp[node][state]
            total = 0
            if state == 0:
                if node.right is not None:
                    total += max(dfs(node.right,0),dfs(node.right,1))
                if node.left is not None:
                    total += max(dfs(node.left,0),dfs(node.left,1))                
            else:
                total += node.val
                if node.right is not None:
                    total += dfs(node.right,0)
                if node.left is not None:
                    total += dfs(node.left,0)
            if node not in dp.keys():
                dp[node] = [-1,-1]
            dp[node][state] = total
            return total
        return max(dfs(root,0),dfs(root,1))
```
为什么这段代码这么慢呢？是因为在树形DP中基本不会有重复子问题的出现，每颗子树与每颗子树之间是相互独立的，基本不会重复计算，因此无需永久存储一个状态只需临时返回即可，这也是树形DP区别于别的需要记忆化搜索加快速度的一个大的原因，树形DP一个节点的状态只供它的父节点使用，而图不是，我主要是想看看python怎么实现结构体的记忆化数组，没想到用dict就行，这里的记忆化搜索适用范围更大，在C++中可以使用数组存。
在给一段不永久存储搜过状态的树形DP做法（仅适用于树形DP），而在图上做DP就需要用到记忆化搜索，

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def rob(self, root: TreeNode) -> int:
        def dfs(node):
            if node is None:
                return [0,0]
            
            left = dfs(node.left)
            right = dfs(node.right)               

            return [max(left)+max(right),node.val+left[0]+right[0]]
        
        a = dfs(root)
        return max(a[0],a[1])
```
