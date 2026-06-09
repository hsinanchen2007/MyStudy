对于二叉树的递归解法，我们只需要考虑root、left_tree、right_tree三部分。

因此，考虑p、q的位置，一共有四种情况：

1. p或q为root
2. p、q在不同子树
3. p、q在同一子树
4. p、q不在此树中

接下来分别对这四种情况进行分析：

1. p或q为root：
   - 若p为root，q在子树中，显然root为p、q的最近公共祖先，返回root；
   - 若p为root，q不在子树中，同样返回root，表示p在这棵树中。
2. 当p、q分别在左右子树中时，显然root即为最近公共祖先，返回即可。
3. 当p、q在同一子树中，返回该子树的返回值即可。
4. 若子树中不含p、q，返回None，表示该树不含p或q。

不要忘了迭代的边界条件：root为空，返回root即可。此条件可与情况一合并。

```python
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # 边界条件，情况一
        if not root or root == p or root == q:
            return root
        
        l = self.lowestCommonAncestor(root.left, p, q)
        r = self.lowestCommonAncestor(root.right, p, q)
        # 当p、q分别在左右子树中时，显然root即为最近公共祖先，返回即可。
        if l and r:
            return root
        # 合并了情况三、四
        return l or r 
```

 