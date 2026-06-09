递归，不断交换左右子树，直到子树为空

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
    public TreeNode invertTree(TreeNode root) {
        if (root != null) {
            TreeNode tempNode = invertTree(root.left);
            root.left = invertTree(root.right);
            root.right = tempNode;
        }
        return root;
    }
}
```