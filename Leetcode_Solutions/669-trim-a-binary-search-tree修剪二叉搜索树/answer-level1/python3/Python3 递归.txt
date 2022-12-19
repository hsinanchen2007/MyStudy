想法很直观，若根节点在指定范围内，则处理其左右子节点；若根节点值小于L，则要替换为其左子节点；若根节点值大于R，则要替换为其右子节点。递归处理即可。
```
class Solution(object):
    def trimBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: TreeNode
        """
        if not root:
            return
        if root.val > R:
            root = self.trimBST(root.left, L, R)
        elif root.val <= R and root.val >= L:
            root.left = self.trimBST(root.left, L, R)
            root.right = self.trimBST(root.right, L, R)
        else:
            root = self.trimBST(root.right, L, R)
        return root
```
