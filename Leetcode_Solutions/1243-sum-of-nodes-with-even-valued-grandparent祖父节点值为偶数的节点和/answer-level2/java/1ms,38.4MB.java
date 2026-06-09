

代码：
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
    public int sumEvenGrandparent(TreeNode root) {
      return dfs(root,null,null);
    }
    int dfs(TreeNode root,TreeNode father,TreeNode grandfather){
        if(root==null) return 0;
        int res=0;
        if(grandfather!=null){
            if(grandfather.val%2==0) res=root.val;
        }
        return dfs(root.left,root,father)+dfs(root.right,root,father)+res;
    }
}