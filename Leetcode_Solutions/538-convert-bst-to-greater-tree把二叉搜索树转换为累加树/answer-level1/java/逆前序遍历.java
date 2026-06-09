```java
class Solution {
    private int sum = 0;

    public TreeNode convertBST(TreeNode root) {
        if (root == null) {
            return null;
        }
        reversePreOrder(root);
        return root;
    }

    private void reversePreOrder(TreeNode root) {
        if (root == null) {
            return;
        }
        reversePreOrder(root.right);
        sum += root.val;
        root.val = sum;
        reversePreOrder(root.left);
    }
}
```
