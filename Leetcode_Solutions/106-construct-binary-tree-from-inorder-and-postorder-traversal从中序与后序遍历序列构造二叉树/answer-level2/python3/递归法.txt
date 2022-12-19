```
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        def mktree(inorder, postorder):
            if len(postorder) == 0:
                return None
            n = TreeNode(postorder[-1])
            i = inorder.index(n.val)
            n.left = mktree(inorder[:i], postorder[:i])
            n.right = mktree(inorder[i+1:], postorder[i:-1])
            return n
        return mktree(inorder,postorder)
```
