代码如下：
public int maxDepth(TreeNode root) {
    if (root == null) {
        return 0;
    }
    return 1 + Math.max(maxDepth(root.right), maxDepth(root.left));
}
我用的是递归