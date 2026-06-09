### 解题思路
本题巧用递归的思想很好解决问题

- 将二叉树的**左右子树依次翻转**

- 等翻转过后再用**根节点连不同的子树**即可。

### 代码

```java []
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
        if (root == null) {
            return null;
        }
        // 将左右子树翻转
        TreeNode left = invertTree(root.left);
        TreeNode right = invertTree(root.right);
        // 然后根节点左连右子树，右连左子树
        root.left = right;
        root.right = left;
        
        return root;
    }
}
```