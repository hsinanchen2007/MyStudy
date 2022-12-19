### 解题思路
思想转换：将一颗树的对称树与其对比，如果一致则是符合题目条件的对称树！

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

        return checkTwoTree(root, root);
    }

    private boolean checkTwoTree(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) {
            return true;
        }
        if (root1 == null || root2 == null) {
            return false;
        }
        if (root1.val != root2.val) {
            return false;
        }

        return checkTwoTree(root1.left, root2.right) && checkTwoTree(root1.right, root2.left);
    }
}
```