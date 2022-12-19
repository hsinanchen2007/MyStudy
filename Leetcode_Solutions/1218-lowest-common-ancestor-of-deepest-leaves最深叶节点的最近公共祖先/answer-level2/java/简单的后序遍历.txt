```java
class Solution {
    private TreeNode node;
    private int maxDepth;
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        if (root == null) {
            return null;
        }
        dfs(root, 0);
        return node;
    }

    private int dfs(TreeNode root, int depth) {
        if (root == null) {
            return depth;
        }
        depth++;
        int left = dfs(root.left, depth), right = dfs(root.right, depth);
        depth = Math.max(left, right);
        if (left == right && depth >= maxDepth) {
            node = root;
            maxDepth = depth;
        }
        return depth;
    }
}
```
