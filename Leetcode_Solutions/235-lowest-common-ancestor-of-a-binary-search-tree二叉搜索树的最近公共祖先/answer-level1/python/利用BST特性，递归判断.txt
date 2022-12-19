### 解题思路
利用 BST 特性，若
- 当 p, q 均为 None 时，返回 None
- 当 root (当前节点)为 None 时，返回 None
- 当 p, q 中任意一个等于 root 时，返回 root
- 当 p, q 中一个大于 root，一个小于 root，返回 root
- 当 p, q 均小于 root，递归调用左子树查询
- 当 p, q 均大于 root，递归调用右子树查询

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if p == None and q == None:
            return None
        elif root == None:
            return None
        elif p != None and p.val == root.val:
            return root
        elif q != None and q.val == root.val:
            return root
        if p != None and q != None:
            if max(p.val, q.val) > root.val and min(p.val, q.val) < root.val:
                return root
        tmp = p
        if tmp == None:
            tmp = q
        if tmp.val < root.val:
            return self.lowestCommonAncestor(root.left, p, q)
        else:
            return self.lowestCommonAncestor(root.right, p, q)
            

```