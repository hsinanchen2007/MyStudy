### 解题思路
递归，每次传入最大值最小值

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
    private static final long MIN = Long.MIN_VALUE;
    private static final long MAX = Long.MAX_VALUE;

    public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }

        return isVaildBSTCore(root.left, MIN, root.val) && isVaildBSTCore(root.right, root.val, MAX);
    }

    private boolean isVaildBSTCore(TreeNode root, long min, long max) {
        if (root == null) {
            return true;
        }

        if (root.val >= max || root.val <= min) {
            return false;
        }

        return isVaildBSTCore(root.left, min, root.val) && isVaildBSTCore(root.right, root.val, max);
    }
}
```