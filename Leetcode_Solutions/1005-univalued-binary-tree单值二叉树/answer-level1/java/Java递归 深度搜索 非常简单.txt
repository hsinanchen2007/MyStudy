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
    public boolean isUnivalTree(TreeNode root) {
        return help(root,root.val);
    }

    private boolean help(TreeNode root,int val){
        if(root==null)
            return true;
        if(root.val!=val)
            return false;
        return help(root.left,val)&&help(root.right,val);
    }
}
```
