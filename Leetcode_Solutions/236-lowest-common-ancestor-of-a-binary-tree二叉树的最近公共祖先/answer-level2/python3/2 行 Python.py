```Python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        l, r = map(lambda x: x and self.lowestCommonAncestor(x, p, q), (root.left, root.right))
        return (root in (p, q) or l and r) and root or l or r
```
递归全部节点，p 的祖先节点全部返回 p，q 的祖先节点全部返回 q，除非它同时是俩个节点的最近祖先，也就是 p，q 分别位于左右子树，那么返回自身
- 这思路用在 [235](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) 也行
