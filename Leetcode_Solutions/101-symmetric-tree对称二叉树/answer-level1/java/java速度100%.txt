### 解题思路
正常判空  然后递归

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
        if (root.left == null && root.right == null) {
            return true;
        }
        if (root.left == null || root.right == null) {
            return false;
        }
        if (root.left.val == root.right.val) {
            TreeNode treeNode_left = new TreeNode(1);
            treeNode_left.left = root.left.left;
            treeNode_left.right = root.right.right;
            TreeNode treeNode_right = new TreeNode(-11);
            treeNode_right.left = root.left.right;
            treeNode_right.right = root.right.left;
            return isSymmetric(treeNode_left) && isSymmetric(treeNode_right);

        }
        return false;
    }

    
}
```