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
class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        root = h(root, val);
        return root;
    }

    private TreeNode h(TreeNode r, int val) {
        if(r == null) {
            r = new TreeNode(val);
            return r;
        }
        if(val > r.val)
            r.right = h(r.right, val);
        else    
            r.left = h(r.left, val);
        return r;
    }
}
```
