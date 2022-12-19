```java
class Solution {
    private int minDiff = Integer.MAX_VALUE;
    private int pre = -1;
    public int getMinimumDifference(TreeNode root) {
        if (root == null) {
            return 0;
        }
        inOrder(root);
        return minDiff;
    }

    private void inOrder(TreeNode root) {
        if (root == null) {
            return;
        }
        inOrder(root.left);
        if (pre >= 0) {
            minDiff = Math.min(minDiff, root.val - pre);
        }
        pre = root.val;
        inOrder(root.right);
    }
}
```
