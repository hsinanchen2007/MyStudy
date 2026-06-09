class Solution {
    public TreeNode invertTree(TreeNode root) {
        if(root == null) return null;
        helper(root);
        return root;
    }
        void helper(TreeNode  root) {
        if(root == null) return;
        if(root.right == null && root.left == null) {
            return;
        }
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        helper(root.left);
        helper(root.right);
    }
}

