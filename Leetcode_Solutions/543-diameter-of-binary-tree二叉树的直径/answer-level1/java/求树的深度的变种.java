求二叉树的直径，实际上就是求所有节点中，左子树的深度+右子树的深度 的最大值。
```java
    private int longestPath = 0;

    public int diameterOfBinaryTree (TreeNode root) {
        depth(root);
        return longestPath;
    }

    private int depth (TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = depth(root.left);
        int r = depth(root.right);
        longestPath = Math.max(longestPath, l + r);
        return Math.max(l, r) + 1;
    }
```