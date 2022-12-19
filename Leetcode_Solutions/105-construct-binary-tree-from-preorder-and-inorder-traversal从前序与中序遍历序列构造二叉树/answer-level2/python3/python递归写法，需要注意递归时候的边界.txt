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
        di = {}
        for i in range(len(inorder)):
            di[inorder[i]] = i
        
        def ds(preorder,st,en,st1,en1,di):
            if st>en:
                return None
            f = preorder[st]
            ind = di[f]
            length = ind-st1
            root = TreeNode(f)
            root.left = ds(preorder,st+1,length+st,st1,ind-1,di)
            root.right = ds(preorder,length+st+1,en,ind+1,en1,di)
            return root
        return ds(preorder,0,len(preorder)-1,0,len(preorder)-1,di)
```