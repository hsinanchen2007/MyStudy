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
    public TreeNode mirrorTree(TreeNode root) {
        TreeNode temp;
        if (root == null) {
            return root;
        }
        else {
            temp = root.right;
            root.right = root.left;
            root.left = temp;
            mirrorTree(root.left);
            mirrorTree(root.right);
            return root;
        }
    }
}
```
用了递归，双100。