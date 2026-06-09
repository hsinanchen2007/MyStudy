```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
 // 寻找规律，进行只针对的变换
class Solution {
    public TreeNode upsideDownBinaryTree(TreeNode root) {
        TreeNode parent_left = null, parent_right = null;
        while(root!=null) {
           TreeNode root_left = root.left;
           TreeNode root_right = root.right; 
           root.left = parent_left;
           root.right = parent_right;
           parent_right = root;
           parent_left = root_right;
           root = root_left;
        }
        return parent_right;
    }
}
```
