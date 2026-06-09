```
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if not root:
            return True
        pre = None
        stack = []
        pnt = root
        while stack or pnt:
            while pnt:
                stack.append(pnt)
                pnt = pnt.left
            if stack:
                pnt = stack.pop()
                if (pre == None) or (pnt.val > pre):
                    pre = pnt.val
                else:
                    return False
                pnt = pnt.right
        return True
```
