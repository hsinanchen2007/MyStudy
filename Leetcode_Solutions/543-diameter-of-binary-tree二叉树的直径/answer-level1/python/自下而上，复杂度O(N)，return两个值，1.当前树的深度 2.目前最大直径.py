```
class Solution(object):
    def diameterOfBinaryTree(self, root):
        return self.diameterHelper(root)[1]
        
    def diameterHelper(self, root):
        if not root:
            return [0,0]
        if not root.left and not root.right:
            return [1,0]
        l = self.diameterHelper(root.left)
        r = self.diameterHelper(root.right)
        return [max(l[0],r[0])+1, max(l[0]+r[0],l[1],r[1])]
```
