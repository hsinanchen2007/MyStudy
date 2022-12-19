### 解题思路
采先访问右分支、再累加节点值，再访问左子树即可

### 代码

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
    private int dfs(TreeNode root, int sum) {
        if (root == null) {
            return sum;
        }
        int right = dfs(root.right, sum);
        root.val += right;
        int left = dfs(root.left, root.val);
        return Math.max(root.val, left);
    }
}
```