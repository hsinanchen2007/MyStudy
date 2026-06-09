```java
class Solution {
    private int diff = Integer.MAX_VALUE;
    private int pre;
    private boolean flag = false;
    public int minDiffInBST(TreeNode root) {
        if (root == null) {
            return 0;
        }
        inOrder(root);
        return diff;
    }

    private void inOrder(TreeNode root) {
        if (root == null) {
            return;
        }
        inOrder(root.left);
        if (flag) {
            diff = Math.min(diff, root.val - pre);
        } else {
            flag = true;
        }
        pre = root.val;
        inOrder(root.right);
    }
}
```
