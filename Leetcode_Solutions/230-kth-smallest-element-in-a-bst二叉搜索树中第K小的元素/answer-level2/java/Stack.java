    public int kthSmallest(TreeNode root, int k) {
        if (root != null) {
            LinkedList<TreeNode> stack = new LinkedList<>();
            while (root != null) {
                stack.push(root);
                root = root.left;
            }
            while (!stack.isEmpty()) {
                root = stack.pop();
                k--;
                if (k == 0)
                    return root.val;
                root = root.right;
                while (root != null) {
                    stack.push(root);
                    root = root.left;
                }
            }

        }
        return -1;
    }