### 解题思路
递归调用，时间空间复杂度都是树的高度，一般为logN，最坏为N


### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def splitBST(self, root, V):
        """
        :type root: TreeNode
        :type V: int
        :rtype: List[TreeNode]
        """
        if root is None:            #递归基，空，也就是删除的值在树中没有
            return None,None
        if root.val == V:           #递归基，恰好分开，删除值在树中
            right = root.right
            root.right = None
            return root,right
        if root.val < V:            #当前节点值小于V
            left,right = self.splitBST(root.right,V)
            root.right = left
            return root,right
        if root.val > V:            #当前节点大于V
            left,right = self.splitBST(root.left,V)
            root.left = right
            return left,root
```