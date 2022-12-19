### 解题思路
请参考代码和注解，写的非常清楚了

### 代码

```java
class Solution {
    // 找到二叉树的最小深度
    // 递归
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        // 找到左边子树的高度
        int leftTreeDepth = minDepth(root.left);
        // 找到右边子树的高度
        int rightTreeDepth = minDepth(root.right);
        // 本个节点的高度是1
        int min = 1;
        // 如果左子树和右子树都不为空
        if (root.left != null && root.right != null) {
            // 那么最小高度就是左右子树中比较小的那个+1
            min = Math.min(leftTreeDepth, rightTreeDepth)+1;
        } else if (root.left != null && root.right == null) {
            // 如果左子树不为空，右子树为空
            min = leftTreeDepth + 1;
        } else if (root.left == null && root.right != null) {
            // 如果左子树为空，右子树不为空
            min = rightTreeDepth + 1;
        } else {
            // 两个子树都为空，那就只有1了
            min = 1;
        }
        return min;
}
```