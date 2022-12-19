### 解题思路
左子树是平衡二叉树 右子树是平衡二叉树 而且 左右子树的深度绝对值不超过1

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
        if (root == null) {
            return true;
        }
        return isBalanced(root.left) && isBalanced(root.right) && Math.abs(getMaxLenth(root.left) - getMaxLenth(root.right)) <= 1;
    }

    private int getMaxLenth(TreeNode node) {
        if (node == null) {
            return 0;
        } else {
            return Math.max(getMaxLenth(node.left) + 1, getMaxLenth(node.right) + 1);
        }
    }
}
```