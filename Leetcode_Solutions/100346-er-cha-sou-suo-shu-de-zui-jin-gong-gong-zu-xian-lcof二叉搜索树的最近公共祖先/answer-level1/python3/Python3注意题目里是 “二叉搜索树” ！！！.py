最开始用的是栈来做深度搜索，但是超时了，看了看别人的题解发现用了原来题目说的是 “二叉搜索树”，也就是左子树的值小于自己的值，然后小于右子树的值，有了这个信息就简化了很多。
```
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if p.val == q.val: return p
        now = root
        while True:
            if p.val < now.val and q.val < now.val: now = now.left
            elif p.val > now.val and q.val > now.val: now = now.right
            else: return now
```
