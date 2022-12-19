    boolean flag = false;

    public boolean isValidBST(TreeNode root) {
        if (root != null) {
            if (root.left != null) {
                if (!isValidBST(root.left) || last >= root.val)
                    return false;
            }
            if (flag && last >= root.val)
                return false;
            last = root.val;
            flag = true;
            if (root.right != null) {
                if (!isValidBST(root.right) || last <= root.val)
                    return false;
            }
        }
        return true;
    }