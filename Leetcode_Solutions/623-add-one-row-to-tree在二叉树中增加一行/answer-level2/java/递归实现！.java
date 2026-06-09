### 解题思路

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
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        if (root == null) {
            return null;
        }
        if (d == 0) {
            return root;
        }
        if (d == 1) {
            TreeNode top = new TreeNode(v);
            top.left = root;
            return top;
        }
        if (d == 2) {
            if (root.left != null) {
                TreeNode l = new TreeNode(v);
                l.left = root.left;
                root.left = l;
            }
            if (root.right != null) {
                TreeNode r = new TreeNode(v);
                r.right = root.right;
                root.right = r;
            }
            if (root.left == null) {
                TreeNode l = new TreeNode(v);
                root.left = l;
                
            }
            if (root.right == null) {
                TreeNode r = new TreeNode(v);
                root.right = r;
            }
            return root;
        }
        root.left = addOneRow(root.left, v, d - 1);
        root.right = addOneRow(root.right, v, d - 1);
        return root;
    }
}
```