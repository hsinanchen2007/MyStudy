很好想的方法，但效率略低，应该可以优化成一次遍历解决
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import math
class Solution:
    def __init__(self):
        self.cnt = 0
    def distributeCoins(self, root: TreeNode) -> int:
        # 计算一棵子树的节点数量
        def node_cnt(node):
            if not node: return 0
            if not node.left and not node.right:
                return 1
            return 1 + node_cnt(node.left) + node_cnt(node.right)
        
        # 计算一颗子树的硬币数量
        def coin_cnt(node):
            if not node: return 0
            if not node.left and not node.right:
                return node.val
            return node.val + coin_cnt(node.left) + coin_cnt(node.right)
        
        # 遍历二叉树，计算每个节点的硬币数量-节点数量的绝对值并相加
        def dfs(node):
            if not node:
                return
            self.cnt += math.fabs(coin_cnt(node) - node_cnt(node))
            dfs(node.left)
            dfs(node.right)
        dfs(root)
        return int(self.cnt)

```