### 解题思路
-1做特殊值，避免无用遍历。

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

    public boolean isBalanced(TreeNode root) {
        return travel(root) != -1;
    }

    int travel(TreeNode root) {
        if (root == null) {
            return 0;
        }
        // leaf
        if (root.left == null && root.right == null) {
            return 1;
        }
        int l = travel(root.right);
        if (l == -1) {
            return l;
        }
        int r = travel(root.left);
        if (r == -1) {
            return r;
        }
        if (Math.abs(l-r) > 1) {
            return -1;
        }
        return Math.max(l, r) + 1;
    }
}
```