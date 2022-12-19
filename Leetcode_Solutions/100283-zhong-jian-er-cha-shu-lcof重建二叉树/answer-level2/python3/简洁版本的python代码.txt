### 解题思路
采用递归的思路编写。

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
        if not preorder or not inorder:
            return None

        root = TreeNode(preorder.pop(0))
        #利用python数组的index函数来定位根节点在inorder数组中的位置。
        index = inorder.index(root.val) 
        # preorder数组不需要进行切片操作，递归终止条件主要靠代码前两行中的not inorder来终止。
        root.left = self.buildTree(preorder, inorder[:index])
        root.right = self.buildTree(preorder, inorder[index + 1:])
        return root
```