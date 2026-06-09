```java
    /** 
     * 执行用时 :1 ms, 100.00%
     * 内存消耗 :39.1 MB, 34.48%
     * 当如下三种情况，当前节点是高度平衡的:
     *  1 root为空
     *  2 root的左右子树都为空
     *  3 root的左右子树高度差的绝对值小于等于1, 且左右子树也高度平衡。
     */
    public boolean isBalanced(TreeNode root) {
        return root == null
                || root.left == null && root.right == null
                || Math.abs(length(root.left) - length(root.right)) <= 1
                && isBalanced(root.left)
                && isBalanced(root.right);
    }

    private int length(TreeNode root) {
        return root == null ? 0 : Math.max(1 + length(root.left), 1 + length(root.right));
    }
```
