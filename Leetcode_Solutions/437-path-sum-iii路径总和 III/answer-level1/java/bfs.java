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
    int result = 0;
    public int pathSum(TreeNode root, int sum) {
        if (root == null) {
            return result;
        }
        bfs(root, sum);

        pathSum(root.left, sum);
        pathSum(root.right, sum);
        return result;
    }

    void bfs(TreeNode root, int sum) {
        if (root == null) {
            return;
        }
        sum -= root.val;
        if (sum == 0) {
            result++;
        }
        bfs(root.left, sum);
        bfs(root.right, sum);
    }
}
```