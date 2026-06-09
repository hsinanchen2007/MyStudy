### 解题思路
p, q节点的最近公共祖先为：
（1）p或q为另一个节点的祖先。或者
（2）该节点能够让p, q分别在其左右子树

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
        if p.val > q.val:
            temp = p
            p = q
            q = temp
        # print()
        def get_res(root):
            if root is None:
                return None
            if p.val <= root.val and q.val > root.val or p.val < root.val and q.val >= root.val:
                return root
            res = get_res(root.left)
            res = res or get_res(root.right) # 如果已经找到答案了就可以不用遍历右子树
            return res
        return get_res(root)
```