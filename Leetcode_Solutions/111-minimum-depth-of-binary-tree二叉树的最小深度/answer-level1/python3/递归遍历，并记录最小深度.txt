```
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        depth = 0
        
        def checkdepth(n, d):
            nonlocal depth
            if not n:
                return False
            if not n.left and not n.right:
                if depth==0 or d+1<depth:
                    depth = d+1
                return
            checkdepth(n.left, d+1)
            checkdepth(n.right, d+1)
        checkdepth(root, 0)
        return depth
```
