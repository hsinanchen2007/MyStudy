### 解题思路
第一步，根据前序序列里的每一个元素，将中序序列分成两段
第二步，前序序列里的元素为根节点，中序序列的两段分别为左子树和右子树
重复上述两步，直到数组为空
### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if preorder and inorder:
            val = preorder.pop(0)
            node = TreeNode(val)

            node.left = self.buildTree(preorder, inorder[0: inorder.index(val)])
            node.right = self.buildTree(preorder, inorder[inorder.index(val) + 1:])

            return node
```