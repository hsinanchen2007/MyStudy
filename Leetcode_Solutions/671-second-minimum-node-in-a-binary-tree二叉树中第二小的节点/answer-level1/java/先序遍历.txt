```java
class Solution {
    private int min;
    private int smin = -1;
    public int findSecondMinimumValue(TreeNode root) {
        if (root == null) {
            return -1;
        }
        min = root.val;
        preOrder(root);
        return smin;
    }

    private void preOrder(TreeNode root) {
        if (root == null) {
            return;
        }
        if (root.val > min) {
            if (smin == -1 || root.val < smin) {
                smin = root.val;
            }
            return;
        }
        preOrder(root.left);
        preOrder(root.right);
    }
}
```
