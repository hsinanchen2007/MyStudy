```
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        from collections import deque

        queue=deque([(root,0)])
        res=root.val
        level=0
        while queue:
            root,l=queue.popleft()
            if level<l:
                level=l
                res=root.val
            if root.left:
                queue.append((root.left,level+1))
            if root.right:
                queue.append((root.right,level+1))
        return res
```
