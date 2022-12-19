Java  DFS解法， 参考大家的
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode bstToGst(TreeNode root) {
        dfs(root, 0);
        return root;
    }
    private int dfs(TreeNode root, int add) {
        if (root == null) {
            return add;
        }
        int right = dfs(root.right, add);
        root.val = root.val + right;
        int left = dfs(root.left, root.val);
        return left;
    }
}
```