### 解题思路
递归，若root为叶子且为左叶子，则sum += root

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
    private int sum = 0;
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null) {
            return 0;
        }
        reverse(root.left, true);
        reverse(root.right, false);
        return sum;
    }

    public void reverse(TreeNode root, boolean left) {
        if (root == null) {
            return;
        }
        if (root.left == null && root.right == null && left) {
            sum += root.val;
        }
        reverse(root.left, true);
        reverse(root.right, false);
    }
}
```