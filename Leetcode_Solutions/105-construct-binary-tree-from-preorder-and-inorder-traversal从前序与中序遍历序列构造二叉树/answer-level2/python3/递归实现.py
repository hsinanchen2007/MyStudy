```
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def dotree(preorder, inorder):
            if len(inorder) == 0:
                return None
            n = TreeNode(preorder[0])
            i = inorder.index(preorder[0])
            del preorder[0]
            l = inorder[:i]
            r = inorder[i+1:]
            n.left = dotree(preorder, l)
            n.right = dotree(preorder, r)
            return n
        return dotree(preorder, inorder)
```
