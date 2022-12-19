```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        return root and (root.val == val and root or self.searchBST((root.left, root.right)[root.val < val], val))
```
- 根据BST的特性，对于每个节点：
	- 如果目标值等于节点的值，则返回节点;
	- 如果目标值小于节点的值，则继续在左子树中搜索;
	- 如果目标值大于节点的值，则继续在右子树中搜索。
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root or root.val == val:
            return root
        else:
            root = root.right if root.val < val else root.left
            return self.searchBST(root, val)
```
- 可读性增强版