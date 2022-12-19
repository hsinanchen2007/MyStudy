官方解法，我的理解是复制出来一棵树，然后镜像对比，为何不直接左右两颗树对比呢，这样要省事一半吧。
只需要先判断一下根节点是否为空，然后就可以左右树进行与官方解法一样的镜像对比了。以下两种解法都是95%+的。

迭代解法
```
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root: return True
        queue = [root.left, root.right]        
        while queue:   
            n1, n2 = queue.pop(), queue.pop()            
            if not n1 and not n2: continue     
            if not n1 or not n2: return False
            if n1.val != n2.val: return False
            queue.append(n1.left)
            queue.append(n2.right)
            queue.append(n1.right)
            queue.append(n2.left)            
        return True
```

递归解法
```
class Solution:
        def isMirror(n1, n2):
            if not n1 and not n2: return True
            if not n1 or not n2: return False
            return n1.val == n2.val and isMirror(n1.left, n2.right) \
                   and isMirror(n1.right, n2.left)

        if not root: return True
        else: return isMirror(root.left, root.right)
```
