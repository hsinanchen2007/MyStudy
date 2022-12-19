
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
    public int kthSmallest(TreeNode root, int k) {
        if (root == null) {
            return 0;
        }
        int leftCount = calcCount(root.left);
        if (k <= leftCount) {
            return kthSmallest(root.left, k);
        } else if (k == leftCount + 1) {
            return root.val;
        } else {
            return kthSmallest(root.right, k - leftCount - 1);
        }
    }

    int calcCount(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return 1 + calcCount(root.left) + calcCount(root.right);
    }
}
```