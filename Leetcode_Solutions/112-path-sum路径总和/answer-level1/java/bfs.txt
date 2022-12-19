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
    public boolean hasPathSum(TreeNode root, int sum) {
        return travel(root, sum) > 0;
    }

    int travel(TreeNode root, int sum) {
        if (root == null) {
            return 0;
        }
        sum -= root.val;
        if (root.left == null && root.right == null && sum == 0) {
            return 1 + travel(root.left, sum) + travel(root.right, sum);
        }
        return travel(root.left, sum) + travel(root.right, sum);
    }

}
```