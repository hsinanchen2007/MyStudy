通过闭包记录最大深度和最大深度的和，DFS和BFS都可以解决，就贴下周赛时写的DFS的代码吧。

![执行结果.png](https://pic.leetcode-cn.com/b4470385d1fd23bc28a3271d764ade314a77ee2cae0eff3b4c013ad0e3bc41b0-%E6%89%A7%E8%A1%8C%E7%BB%93%E6%9E%9C.png)

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        # max_deep, sum_val
        v = [-1, 0]
        def dfs(r, deep):
            if deep > v[0]:
                v[0] = deep
                v[1] = r.val 
            elif deep == v[0]:
                v[1] += r.val
            if r.left:
                dfs(r.left, deep + 1)
            if r.right:
                dfs(r.right, deep + 1)
        dfs(root, 0)
        return v[1]
```
