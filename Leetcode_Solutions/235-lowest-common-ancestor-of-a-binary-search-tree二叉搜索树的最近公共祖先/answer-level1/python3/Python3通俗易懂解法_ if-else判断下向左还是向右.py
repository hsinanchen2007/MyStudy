### 解题思路
注意着是搜索二叉树, 也就是左右子节点代表小于大于.
直接写if - else来判断. 
相等直接返回t
p, q 同侧则继续递归搜索这一侧
p, q 不同侧则直接返回t

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
        t = root
        if p.val == t.val:
            return p
        elif q.val == t.val:
            return q
        elif p.val < t.val and q.val < t.val:
            return self.lowestCommonAncestor(root.left, p, q)
        elif p.val > t.val and q.val > t.val:
            return self.lowestCommonAncestor(root.right, p, q)
        else:
            return t
```