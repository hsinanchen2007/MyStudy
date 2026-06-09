
    public int findTilt(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Stack<TreeNode> stack = new Stack<>();
        LinkedList<TreeNode> list = new LinkedList<>();
        stack.push(root);
        int p = 0;
        while (!stack.isEmpty()) {
            TreeNode treeNode = stack.pop();
            list.addFirst(treeNode);
            if (treeNode.left != null) {
                stack.push(treeNode.left);
            }if (treeNode.right != null) {
                stack.push(treeNode.right);
            }
        }
        for (TreeNode treeNode : list) {
            int left = treeNode.left == null? 0:treeNode.left.val;
            int right = treeNode.right == null? 0:treeNode.right.val;
            p += Math.abs(left - right);
            treeNode.val = left + right + treeNode.val;
        }
        return p;
    }