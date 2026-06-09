```Java
/**
 * 二叉树的直径
 */
public int diameterOfBinaryTree(TreeNode root) {
    if (root == null) {
        return 0;
    }
    // 经过当前点的直径
    int currentDiameter = depth(root.left) + depth(root.right);
    // 当前点直径、左子树直径 和 右子树直径 的 最大值
    return max(currentDiameter, diameterOfBinaryTree(root.left), diameterOfBinaryTree(root.right));
    }

/**
 * 二叉树的最大深度
 */
public int depth(TreeNode root) {
    if (root == null) {
        return 0;
    }
    return 1 + Math.max(depth(root.left), depth(root.right));
}

/**
 * 最大值
 */
public int max(int a, int b, int c) {
    return Math.max(Math.max(a, b), c);
}
```
