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
   int ans=0;
	    public int diameterOfBinaryTree(TreeNode root) {
	    	dfs(root);
	    	return ans;
	}
		private int dfs(TreeNode root) {
			// TODO Auto-generated method stub
			if(root==null) {
				return 0;
			}
			int letf = dfs(root.left);
			int right = dfs(root.right);
			ans = Math.max(ans, letf+right);
			return Math.max(letf, right)+1;
		}
}