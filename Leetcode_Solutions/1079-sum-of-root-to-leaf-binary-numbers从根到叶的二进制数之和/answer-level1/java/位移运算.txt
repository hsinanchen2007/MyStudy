```java
class Solution {
    private int sum;
    private int mod = 1000_000_007;
    public int sumRootToLeaf(TreeNode root) {
        if (root == null) {
            return 0;
        }
        dfs(root, 0);
        return sum;
    }

    private void dfs(TreeNode root, int val) {
        if (root == null) {
            return;
        }
        val += root.val;
        if (root.left == null && root.right == null) {
            sum = (sum + val) % mod;
        } else {
            val <<= 1;
            dfs(root.left, val);
            dfs(root.right, val);
        }
    }
}
```
