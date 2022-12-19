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
    public boolean checkSubTree(TreeNode t1, TreeNode t2) {
        if(t1==null && t2==null)    return true;
        if(t1==null || t2==null)    return false;

        return isSubTree(t1.left, t2) || isSubTree(t1.right, t2);
    }
    private boolean isSubTree(TreeNode t1, TreeNode t2){
        if(t1==null && t2==null)    return true;
        if(t1==null || t2==null)    return false;

        if(isEqual(t1, t2)){
            return true;
        }else{
            return isSubTree(t1.left, t2) || isSubTree(t1.right, t2);
        }
    }
    private boolean isEqual(TreeNode t1, TreeNode t2){
        if(t1==null && t2==null)    return true;
        if(t1==null || t2==null)    return false;

        if(t1.val != t2.val){
            return false;
        }else{
            return isEqual(t1.left, t2.left) && isEqual(t1.right, t2.right);
        }
    }
}