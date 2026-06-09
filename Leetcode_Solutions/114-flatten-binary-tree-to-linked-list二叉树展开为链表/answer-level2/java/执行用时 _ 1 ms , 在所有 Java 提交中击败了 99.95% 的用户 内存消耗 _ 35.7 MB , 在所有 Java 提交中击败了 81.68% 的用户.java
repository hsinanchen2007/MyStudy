    public void flatten(TreeNode root) {
        reduce(root);
    }

    TreeNode reduce(TreeNode root) {
        if (root == null)
            return null;
        TreeNode pre1 = reduce(root.left);
        if (pre1 == null)
            pre1 = root;

        TreeNode right = root.right;
        root.right = root.left;
        root.left = null;
        TreeNode pre2 = reduce(right);

        pre1.right = right;
        return pre2 == null ? pre1 : pre2;
    }