```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode, first=True) -> bool:
        if not root: return first or 0
        l, r = map(lambda x: self.isBalanced(x, False), [root.left, root.right])
        return max(l,r)+1 if min(l,r)>-1 and abs(l-r)<=1 else (-1, False)[first]
```
- DFS递归每个节点
- 如果这个节点不平衡，那么这棵树肯定不平衡，它和它的所有父节点都返回 -1（根节点返回False）
- 如果节点平衡，则返回当前树的高度 + 1（根节点返回True）