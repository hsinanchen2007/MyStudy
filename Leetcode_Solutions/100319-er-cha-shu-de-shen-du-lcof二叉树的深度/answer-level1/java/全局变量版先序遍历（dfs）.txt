### 解题思路
一开始没get到标准解的dfs，于是写了这么个破玩意儿

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
    private int depth = 0;
    private int ans = 0;
    public int maxDepth(TreeNode root) {
        if(root == null) {
            return 0;
        }
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode root) {
        if(root != null) {
            depth++;
        }
        if(root.left == null && root.right == null) {
            if (depth > ans) {
                ans = depth;
            }
        }
        if(root.left != null)
            dfs(root.left);

        if(root.right != null) {
            dfs(root.right);
        }
        depth--;
    }
}
```