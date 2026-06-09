### 解题思路
此处撰写解题思路

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
        if (root == null) {
            return false;
        }
        if (root.left == null && root.right == null) {
            return root.val == sum;
        }
        return loopTreeNode(root, 0, sum);
    }

    public boolean loopTreeNode(TreeNode root, int currentSum, int targetSum) {
        if (root == null) return false;

        if (currentSum + root.val == targetSum
                && root.left == null
                && root.right == null) {
            return true;
        }
        else if (root.left == null && root.right == null) {
            return false;
        }

        boolean leftBoo = loopTreeNode(root.left, currentSum + root.val, targetSum);
        boolean rightBoo = loopTreeNode(root.right, currentSum + root.val, targetSum);


        return leftBoo || rightBoo;
    }
}
```