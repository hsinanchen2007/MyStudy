### 解题思路
因为是求任意一条路径，所以在递归求解左右子树的最大长度后，别忘了和0进行比较
int left = Math.max(helper(root.left), 0);
int right = Math.max(helper(root.right), 0);

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
    int res = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        helper(root);
        return res;
    }

    int helper(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = Math.max(helper(root.left), 0);
        int right = Math.max(helper(root.right), 0);
        res = Math.max(res, left + right + root.val);
        return Math.max(left + root.val, right + root.val);
    }
}
```