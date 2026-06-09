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
    int min=Integer.MAX_VALUE;
    TreeNode pre=null;
    public int getMinimumDifference(TreeNode root) {
        return inorder(root);
    }

    private int inorder(TreeNode root){
        if(root==null)
            return 0;
        inorder(root.left);
        if(pre!=null)
            min=Math.min(min,Math.abs(pre.val-root.val));
        pre=root;
        inorder(root.right);
        return min;
    }
}
```
