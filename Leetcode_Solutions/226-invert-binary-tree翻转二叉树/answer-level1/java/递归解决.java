### 解题思路
先遍历到叶子节点，然后交换左右子节点，返回父节点

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
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode nodeLeft = invertTree(root.left);
        TreeNode nodeRight = invertTree(root.right);
        root.left = nodeRight;
        root.right = nodeLeft;
        return root;
    }
}
```