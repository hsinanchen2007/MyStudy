### 解题思路
前序遍历和中序遍历构造二叉树，递归构造

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def pioderbt(preorder,inorder):
            if(not inorder):
                return None
            root = TreeNode(preorder[0])
            i = inorder.index(preorder[0])
            root.left = pioderbt(preorder[1:i+1],inorder[0:i])
            root.right = pioderbt(preorder[i+1:],inorder[i+1:])
            return root
        return pioderbt(preorder,inorder)
```