```
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        try:
            if PreOrder(p, q) == False:
                return False
        except AttributeError as e:
            return False
        return True
          
def PreOrder(p,q):
    if p == None and q == None:
        return
    if p.val != q.val:
        return False
    if PreOrder(p.left, q.left) == False:
        return False
    if PreOrder(p.right, q.right) == False:
        return False
```

1. **树结构不相同**时直接返回False
2. 在判断树结构是否相同的同时**判断每个节点的值是否相同**，不同则返回False

