/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import java.lang.Math;
class Solution {
    private boolean res = true;
    public boolean isBalanced(TreeNode root) {
        maxDepth(root);
        return res;
    }
    
    /*辅助函数就是求树的最大深度的，
    在其中加了一条判断左右子树最大深度差的语句*/
    private int maxDepth(TreeNode root){
        if (root == null) return 0;
        int left = maxDepth(root.left);
        int right = maxDepth(root.right);
        if (Math.abs(left - right) > 1) res = false;
        return Math.max(left, right) + 1;
    }
}