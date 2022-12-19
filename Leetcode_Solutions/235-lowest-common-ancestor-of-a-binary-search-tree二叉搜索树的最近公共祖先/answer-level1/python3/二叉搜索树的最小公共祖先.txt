- **思路**

利用二叉搜索树的特性，可以通过比较所找节点与根节点的大小确认其所在的子树，若两节点都在左子树或右子树，则递归搜索，若一边一个，则返回根节点。

- **实例**

实例1：利用递归
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if p.val > root.val < q.val:
            return self.lowestCommonAncestor(root.right, p, q)
        elif p.val < root.val > q.val:
            return self.lowestCommonAncestor(root.left, p, q)
        else: return root
```
实例2：非递归
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        while root:
            if p.val > root.val < q.val:
                root = root.right
            elif p.val < root.val > q.val:
                root = root.left
            else:
                return root
```
- **结果**

实例1：

执行用时 : 140 ms, 在Lowest Common Ancestor of a Binary Search Tree的Python3提交中击败了37.06% 的用户

内存消耗 : 17.2 MB, 在Lowest Common Ancestor of a Binary Search Tree的Python3提交中击败了93.84% 的用户



实例2：

执行用时 : 112 ms, 在Lowest Common Ancestor of a Binary Search Tree的Python3提交中击败了90.42% 的用户

内存消耗 : 17.2 MB, 在Lowest Common Ancestor of a Binary Search Tree的Python3提交中击败了96.12% 的用户