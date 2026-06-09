### 解题思路
        递归：主要有三种情况：
        1.如果当前节点值比p和q大，那么最近公共祖先肯定在左子树；
        2.如果当前节点值比p和q小，那么最近公共祖先肯定在右子树；
        3.如果当前节点值比p小、比q大，或者比p大、比q小，那么最近公共祖先就是当前节点。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        """
        递归：主要有三种情况：
        1.如果当前节点值比p和q大，那么最近公共祖先肯定在左子树；
        2.如果当前节点值比p和q小，那么最近公共祖先肯定在右子树；
        3.如果当前节点值比p小、比q大，或者比p大、比q小，那么最近公共祖先就是当前节点。
        """
        if not root:
            return None
        while root:
            # 结果肯定在左子树
            if root.val > p.val and root.val > q.val:
                return self.lowestCommonAncestor(root.left, p, q)
            # 结果肯定在右子树，当前节点比p和q都小
            elif root.val < p.val and root.val < q.val:
                return self.lowestCommonAncestor(root.right, p, q)
            else: # p和q各在一边，说明当前的根就是最近共同祖先
                return root
                
```