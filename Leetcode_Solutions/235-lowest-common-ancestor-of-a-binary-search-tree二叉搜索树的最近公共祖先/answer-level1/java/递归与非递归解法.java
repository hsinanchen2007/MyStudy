**思路: BST所有左子树 < 根 < 右子树**
# 递归
```
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == p || root == q || (Math.min(p.val, q.val) < root.val && root.val < Math.max(p.val, q.val))) return root;
        return p.val > root.val ? lowestCommonAncestor(root.right, p, q) : lowestCommonAncestor(root.left, p, q);
    }
}
```
时间复杂度: O(h)
空间复杂度: O(h)
# 非递归
```
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode result = root;
        while (result != null) {
            if (result == p || result == q || (Math.min(p.val, q.val) < result.val && result.val < Math.max(p.val, q.val))) break;
            result = p.val < result.val ? result.left : result.right;
        }
        return result;
    }
}
```
时间复杂度: O(h)
空间复杂度: O(1)