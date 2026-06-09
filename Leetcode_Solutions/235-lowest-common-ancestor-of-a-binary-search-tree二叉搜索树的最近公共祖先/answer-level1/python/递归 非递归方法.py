### 解题思路
此处撰写解题思路

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
        # 非递归方法 时间104ms 如果根节点大于p，q 那么要求的结点肯定在 左子树 如果根节点小于p,q 那么肯定在右子树 ，如果两种条件都不是 那么就是我们要求的结点
        while root!=None:
            if root.val > p.val and root.val >q.val:
                root = root.left
            elif root.val < p.val and root.val < q.val:
                root = root.right
            else:
                return root
        return root

        
        # if root.val>p.val and root.val>q.val:
        #     return self.lowestCommonAncestor(root.left, p, q);
        # if root.val<p.val and root.val<q.val:
        #     return self.lowestCommonAncestor(root.right,p,q);
        # return root;

```