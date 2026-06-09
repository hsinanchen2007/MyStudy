二叉搜索树会让这个题变得很简单
```python
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':

        if not root:
            return None

        # 如果当前根值大于两个值，那说明pq都在左子树
        if root.val > p.val and root.val > q.val:
            return self.lowestCommonAncestor(root.left, p, q)

        # 如果当前根值小于两个值，那说明pq都在右子树
        elif root.val < p.val and root.val < q.val:
            return self.lowestCommonAncestor(root.right, p, q)
        
        # 不然pq肯定是在两边，那说明当前的根就是共同祖先
        else:
            return root
```
如果是一般的二叉树，就一定要判断到节点为p或者q为止

```python
class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        # 如果当前节点为空，就返回空
        if not root:
            return None
        # 如果当前结点就是p或者q，就返回当前节点
        if root in [p, q]:
            return root
        
        # 分别去左右子树里面去找
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        # 如果左右子树里各有一个p或者q，那么当前就是最前结点
        if left and right:
            return root

        # 如果都在左边，那就是当前这个左边的
        elif left:
            return left
        
        # 要么就是右边的
        elif right:
            return right
        
        return None
```

