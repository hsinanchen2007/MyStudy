  深度搜索，定义变量max与当前结点的直径比较
    int max;

    public int diameterOfBinaryTree(TreeNode root) {
        diameterOfBinaryTree2(root, 0);
        return max;
    }

    public int diameterOfBinaryTree2(TreeNode root, int len) {
        if (root == null) {
            return 0;
        }
        int leftLen = diameterOfBinaryTree2(root.left, len);
        int rightLen = diameterOfBinaryTree2(root.right, len);
        max = Math.max(leftLen + rightLen, max);
        return Math.max(leftLen, rightLen) + 1;
    }
