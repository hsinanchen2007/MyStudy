### 代码

```java
class Solution {
    public boolean isValidBST(TreeNode root) {
        return root == null || isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    //左右分别递归
    private boolean isValidBST(TreeNode root,long min,long max) {
        return root.val > min && root.val < max && (root.left == null || isValidBST(root.left, min, Math.min(max, root.val))) && (root.right == null || isValidBST(root.right, Math.max(min, root.val), max));
    }
}
```