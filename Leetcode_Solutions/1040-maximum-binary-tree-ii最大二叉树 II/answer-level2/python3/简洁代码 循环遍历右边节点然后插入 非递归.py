每次与头结点比较，小的话就检查右节点。更新：1）已有的节点变成新节点的左接单，2）新节点变成父节点的右节点。
```
class Solution:
    def insertIntoMaxTree(self, root: TreeNode, val: int) -> TreeNode:
        # dummy
        dummy = TreeNode(0)
        dummy.right = root
        
        # search
        p, c = dummy, dummy.right
        while c and c.val > val:
            p, c = c, c.right
        
        # insert
        n = TreeNode(val)
        p.right = n
        n.left = c
        
        return dummy.right
```
