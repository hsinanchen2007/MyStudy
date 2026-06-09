```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        # 穿过某个根节点的最长路径是 左树的深度+右树的深度
        # 由于计算深度的时候就会用到左右树的深度，因此可以顺便求最长路径
        # 为防止重复计算，在递归的过程中记下以某个节点为根节点的子树的深度
        memo = {}
        result = 0
        def get_depth(node):
            if node is None:
                return 0
            # 取备忘录
            if node in memo:
                return memo[node]
            left = get_depth(node.left)
            right = get_depth(node.right)
            # 顺便求最长路径
            longest = left + right
            nonlocal result
            if longest > result:
                result = longest
            depth = max(left, right) + 1
            # 记录
            memo[node] = depth
            return depth
        get_depth(root)
        return result
```
