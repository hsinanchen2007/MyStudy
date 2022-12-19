```
class Solution {
    private int res = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        depth(root);
        return res;
    }
    public int depth(TreeNode root) {
        if (root == null)
            return 0;
        int left = depth(root.left);
        int right = depth(root.right);
        res = Math.max(res, left + right);
        return 1 + Math.max(left, right);
    }
}
```
