### 解题思路
类似“子树” 判断的递归

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
    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        return isDuiChen(root.left, root.right);
    }

    public boolean isDuiChen(TreeNode left, TreeNode right) {
        if (left == null && right == null) {
            return true;
        }
        if (left == null || right == null) {
            return false;
        }
        if (left.val == right.val) {
            return isDuiChen(left.left, right.right) && isDuiChen(left.right, right.left);
        } else {
            return false;
        }
    }
}
```