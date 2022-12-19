```java
class Solution {
    private int max;

    public int longestUnivaluePath(TreeNode root) {
        dfs(root);
        return max;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int len = 0;
        int res = 0;
        int leftLen, rightLen;
        if (root.left != null) {
            leftLen = dfs(root.left);
            if (root.val == root.left.val) {
                res = (len += (leftLen + 1));
            }
        }
        if (root.right != null) {
            rightLen = dfs(root.right);
            if (root.val == root.right.val) {
                len += (rightLen + 1);
                res = Math.max(res, rightLen + 1);
            }
        }
        max = Math.max(max, len);
        return res;
    }
}
```
