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
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (root.left == null && root.right == null) {
            return 0;
        }

        return middleLoopSum(root, false);
    }

    public int middleLoopSum(TreeNode node, Boolean leftNode) {
        if (node == null) {
            return 0;
        }

        if (node.left == null && node.right == null) {
            if (leftNode) {
                return node.val;
            } else {
                return 0;
            }
        }

        return middleLoopSum(node.left, true)
                + middleLoopSum(node.right, false);
    }
}
```