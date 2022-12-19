``` java
√/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int closestValue(TreeNode root, double target) {
        if (target > root.val) {
            if (root.right == null) {
                return root.val;
            } else {
                double diff = Math.abs(target - root.val);
                int rightMin = closestValue(root.right, target);
                double rightDiff = Math.abs(rightMin - target);
                return diff < rightDiff ? root.val : rightMin;
            }
        } else {
            if (root.left == null) {
                return root.val;
            } else {
                double diff = Math.abs(target - root.val);
                int leftMin = closestValue(root.left, target);
                double leftDiff = Math.abs(leftMin - target);
                return diff < leftDiff ? root.val : leftMin;
            }
        }
    }
}
```