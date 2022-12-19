/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode BstToGst(TreeNode root) {
        update(root,0);
        return root;
    }
    public int update(TreeNode root,int basenum)
    {

        if(root==null)
            return 0;
        int old = root.val;
        int r = update(root.right,basenum);
        int l = update(root.left,r+old+basenum);
        root.val = r+root.val+basenum;
        return old+r+l;
    }
}