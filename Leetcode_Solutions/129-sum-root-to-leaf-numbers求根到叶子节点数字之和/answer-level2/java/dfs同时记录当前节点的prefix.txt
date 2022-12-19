class Solution {
    int sum = 0;
    public int sumNumbers(TreeNode root) {
        traverse(root, 0);
        return sum;
    }

    private void traverse(TreeNode root, int prefix) {
        if (root == null) return;
        if (root.left == null && root.right == null) {
            sum += prefix + root.val;
            return;
        }
        traverse(root.left, (prefix + root.val) * 10);
        traverse(root.right, (prefix + root.val) * 10);
    }
}