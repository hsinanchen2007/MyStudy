1. 使用递归的时候经常判断边界, 一般树的边界有两种
    1. 节点tn,  tn.right 是否为None, tn.left 是否为None, 同时为None 则tn为叶节点
    2. 最低端,  tn为当前节点, 判断是否为None

```
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        
        def comtree(t1, t2):
            
            if t1 is None and t2 is None:
                return True
            if t1 is None or t2 is None:
                return False
        
            if t1.val == t2.val:
                return comtree(t1.left, t2.right) and comtree(t1.right, t2.left)
            else:
                return False
            
            
        return comtree(root, root)            
```
2. 两个的区别在这道题中
上述写法为 最低端, tn 是否为None

3. 使用判断叶节点的方法判断是否对称
t1.right.val == t2.left.val and t1.left.val == t2.right.val 
在此基础上 还要判断 t1 的right 和 left 是否为None, t2 的right, left是否为None,
还有 (None, 3, 3, None)  (None, 3, None, 3)这两种情况, 比较复杂

4. 综上使用最低端的方法会好一点, 我写代码会陷入到判断节点左右节点, 大家有意识的思考一下就好