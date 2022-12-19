### 解题思路
此处撰写解题思路

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
        assert len(preorder) == len(inorder)
        if not preorder or not inorder:
            return
        if len(preorder) == 1 and preorder == inorder:
            return TreeNode(preorder[0])

        root = TreeNode(preorder[0])

        def reconstruct(pre_list, in_list):
            if not pre_list:
                return None
            elif len(pre_list) == 1 or len(in_list) == 1:
                return TreeNode(pre_list[0])
            else:
                i = 0 
                while in_list[i] != pre_list[0]:
                    i += 1
                node = TreeNode(pre_list[0])
                node.left = reconstruct(pre_list[1:i+1], in_list[:i])
                if i < len(in_list) - 1:
                    node.right = reconstruct(pre_list[i+1:], in_list[i+1:])
                return node
        return reconstruct(preorder, inorder)


            
            
```