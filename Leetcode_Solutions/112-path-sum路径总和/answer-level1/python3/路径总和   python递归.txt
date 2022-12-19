声明一个变量记录已经经过的节点的值之和，每经过一个节点就加上这个节点的值，在叶子节点判断变量值是否为目标值。
```
class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        def he(root,a,l):
            if root.left == None and root.right == None:
                l.append(a)
            if root.left != None:
                item = root.left
                he(item,a+item.val,l)
            if root.right != None:
                item = root.right
                he(item,a + item.val,l)
            return l
        if not root:
            return False
        a = he(root,root.val,[])
        if sum in a:
            return True
        return False
```




