写两个函数一个用来求该节点到任意子节点的和，另一个遍历所有节点求和
```
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        def he(root,a,l):
            if not root.left and not root.right:
                return
            if root.left:
                item = root.left
                l.append(a+item.val)
                he(item,a+item.val,l)
            if root.right:
                item = root.right
                l.append(a + item.val)
                he(item,a+item.val,l)
            return l
        def he_all(root,a):
            if root.left or root.right:
                t = he(root, root.val, [root.val])
                a += t
            elif not root.left and not root.right:
                a.append(root.val)
            if root.left:
                he_all(root.left,a)
            if root.right:
                he_all(root.right,a)
            return a
        if not root:
            return 0
        a = he_all(root,[])
        return a.count(sum)
```

