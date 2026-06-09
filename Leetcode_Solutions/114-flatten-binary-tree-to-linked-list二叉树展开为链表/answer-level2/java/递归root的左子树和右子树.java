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
        public void flatten(TreeNode root) {
            if (root==null)
                return;
            dfs(root);
        }

        private TreeNode dfs(TreeNode root) {
            if (root.left == null && root.right == null) {
                return root;
            }
            TreeNode right = root.right;
            TreeNode leftEnd = root;
            if (root.left != null) {
                leftEnd = dfs(root.left);
                root.right = root.left;
                root.left=null;
            }
            TreeNode rightEnd = leftEnd;
            if (right != null) {
                rightEnd = dfs(right);
                leftEnd.right = right;
            }
            return rightEnd;
        }
}
```