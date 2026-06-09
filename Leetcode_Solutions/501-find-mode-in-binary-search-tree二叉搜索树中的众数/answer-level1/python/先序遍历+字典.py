```
class Solution:
    def __init__(self):
        self.res={}
    def findMode(self, root: TreeNode) -> List[int]:
        result=[]
        if root==None:
            return []
        self.visit(root)
        Max=max(self.res.values())
        for key in self.res:
            if self.res[key]==Max:
                result.append(key)
        return result


    
    def visit(self,root):
        if root:
            self.res[root.val]=self.res.get(root.val,0)+1
            self.visit(root.left)
            self.visit(root.right)
```
