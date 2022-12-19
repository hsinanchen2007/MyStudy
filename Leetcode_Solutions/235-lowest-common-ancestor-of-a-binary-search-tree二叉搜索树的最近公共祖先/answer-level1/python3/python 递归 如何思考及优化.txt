
见注释 

```
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root:
            return None
        if (p and not q) or (not p and q):  #只有p或者q的情况，祖先必定为p或者q,因为递归所以他们就是此层的root
            return root
        else:                               #剩下就是q,q都存在的情况
            if p.val<root.val>q.val:        #都小于root的值，说明都在左树，在左树继续递归查找
                return self.lowestCommonAncestor(root.left,p,q)
            if p.val>root.val<q.val:        #都大于root的值，在右树继续递归查找
                return self.lowestCommonAncestor(root.right,p,q)
            return root                     #一个在左，一个在右，那么root就是祖先
```

因为（1）p，q只有一个存在（2）q,p都存在分别在左右树的情况都返回root.直接优化得到最简代码。

```
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if p.val<root.val>q.val:
            return self.lowestCommonAncestor(root.left,p,q)
        if p.val>root.val<q.val:
            return self.lowestCommonAncestor(root.right,p,q)
        return root
```
