public boolean isValidBST(TreeNode root) {
        if (root == null) return true;
        if (root.left == null && root.right == null) return true;
        int a = Integer.MIN_VALUE;
        int b = Integer.MAX_VALUE;
        if (root.left != null && root.val <= checkMax(root.left, a)) return false;
        if (root.right != null && root.val >= checkMin(root.right, b)) return false;
        return isValidBST(root.left) && isValidBST(root.right);
    }


    public int checkMax(TreeNode root, int max) {
        max = Math.max(max, root.val);
        if (root.left != null) max = checkMax(root.left, max);
        if (root.right != null) max = checkMax(root.right, max);
        return max;
    }

    public int checkMin(TreeNode root, int min) {
        min = Math.min(min, root.val);
        if (root.left != null) min = checkMin(root.left, min);
        if (root.right != null) min = checkMin(root.right, min);
        return min;
    }