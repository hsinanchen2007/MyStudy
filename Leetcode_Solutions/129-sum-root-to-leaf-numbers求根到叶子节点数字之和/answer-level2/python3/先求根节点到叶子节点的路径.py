先求根节点到叶子节点的路径，之后将paths里面的每一项相加就得到了最终的target：
code
```
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        def alg(rot,path):
            if rot==None:
                return 
            else:
                path+=str(rot.val)
            if rot.left==None and rot.right==None:
                paths.append(path)
            alg(rot.left,path)
            alg(rot.right,path)
            return 
        paths=[]
        alg(root,'')
        target=0
        for i in paths:
            target+=int(i)
        return target
```