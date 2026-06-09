### 解题思路
这道题的思路我觉得不需要多啰嗦，用递归做是标准解法。

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
        def get_res(preorder, inorder):
            if preorder == []:
                return None
            val = preorder[0]
            root = TreeNode(val)
            ind = inorder.index(val)
            root.left = get_res(preorder[1:ind + 1], inorder[:ind])
            root.right = get_res(preorder[ind + 1:], inorder[ind + 1:])
            return root
        return get_res(preorder, inorder)
```