### 解题思路
一做递归头就晕
三种情况：
1. 当前节点值小于左边界，那么把当前节点的右节点当做起始节点，开始向下找（这个地方想了半天才明白，为什么是root = self.trimBST(root.right, L, R)）
2. 当前节点值大于右边界，那么把当前节点的左节点当做起始节点，开始向下找
3. 当前节点在左右边界间，（保留当前节点）左右分别向下继续找。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def trimBST(self, root: TreeNode, L: int, R: int) -> TreeNode:
        if root == None:
            return None
        
        if root.val < L:
            root = self.trimBST(root.right, L, R)  # 这个地方想了半天才明白

        elif root.val > R:
            root = self.trimBST(root.left, L, R)  # 这个地方想了半天才明白
        elif L <= root.val <= R:
            root.left = self.trimBST(root.left, L, R)
            root.right = self. trimBST(root.right, L, R)
        
        return root

```