
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

    private int count = 0;

    public int countUnivalSubtrees(TreeNode root) {
        count = 0;
        dfs(root);
        return count;
    }

    private boolean dfs(TreeNode root) {
        if(root == null) {
            return true;
        }
        boolean leftRes = dfs(root.left);
        boolean rightRes = dfs(root.right);
        if(leftRes && rightRes && 
            (root.left == null || root.left.val == root.val) &&
            (root.right == null || root.right.val == root.val)){
            count++;
            return true;
        }
        return false;
    }
}
```