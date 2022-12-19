```java
    public TreeNode sufficientSubset(TreeNode root, int limit) {
        // 如果根节点为空或根节点也需要删除, 返回null
        if (root == null || DFS(root, limit, root.val)) return null;
        return root;
    }

    private boolean DFS(TreeNode root, int limit, int sum) {
        // 如果为叶子节点, 如果值小于limit, 则可以删除
        if (root.left == null && root.right == null)
            return sum < limit;
        // 如果左(右)子树为null, 默认为true
        boolean left = true, right = true;
        if (root.left != null) {
            left = DFS(root.left, limit, sum + root.left.val);
            // 如果左子树可以被删除, 则删除
            if (left) root.left = null;
        }
        if (root.right != null) {
            right = DFS(root.right, limit, sum + root.right.val);
            // 如果右子树可以被删除, 则删除
            if (right) root.right = null;
        }
        // 如果节点的左右子树都可以被删除, 则该节点也可以被删除
        return left && right;
    }
```