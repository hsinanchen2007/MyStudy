
```
public class Solution {

    public class TreeNode {
        int val;

        TreeNode left;

        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    private int max = Integer.MIN_VALUE;

    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        dfs(root, 0);

        return max;

    }

    private void dfs(TreeNode node, int count) {
        if (node == null) {
            return;
        }
        count++;
        max = Math.max(count, max);
        dfs(node.left, count);
        dfs(node.right, count);
    }

}
```
