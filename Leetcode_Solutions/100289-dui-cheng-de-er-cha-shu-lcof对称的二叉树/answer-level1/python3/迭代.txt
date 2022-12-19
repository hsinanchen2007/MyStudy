```
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def judge(a , b):
            if a and not b or not a and b: return False 
            if not a and not b : return True
            if a.val != b.val: return False
            return True
        if root == None: return True 
        stk = [root, root]
        while stk:
            a = stk.pop()
            b = stk.pop()
           
            if not judge(a, b): return False 
            if not a and not b: continue
            stk.append(a.left)
            stk.append(b.right)
            stk.append(a.right)
            stk.append(b.left)
        return True   
```
