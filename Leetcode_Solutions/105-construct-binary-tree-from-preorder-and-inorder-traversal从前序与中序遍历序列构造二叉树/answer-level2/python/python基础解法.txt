### 解题思路
使用递归，递归的出口就是inorder为空，首先前序遍历的第一个元素就是整个根节点，从inoeder中找到根节点，inorder根节点前面的就是左子树的节点，后面就是右子树的节点，preorder从第二个到mid+1之间就是左子树的节点，从mid+1到最后就是右子树的节点，直接递归下去就可以了

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
        if len(inorder) == 0:
            return None
        root = TreeNode(preorder[0])
        mid = inorder.index(preorder[0])

        root.left = self.buildTree(preorder[1:mid+1], inorder[:mid])
        root.right = self.buildTree(preorder[mid+1:], inorder[mid+1:])
        return root
```