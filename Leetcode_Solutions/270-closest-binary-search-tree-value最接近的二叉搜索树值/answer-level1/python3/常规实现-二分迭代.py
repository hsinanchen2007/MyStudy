```
def closestValue(self, root: TreeNode, target: float) -> int:
        res=root.val
        node=root
        t=int(target+0.5)
        while node!= None:
            if abs(node.val-t)<abs(res-t):
                res=node.val
            if node.val==t:
                res = node.val
                break
            elif node.val>t:
                node=node.left
            else:
                node=node.right
        return res 
```
