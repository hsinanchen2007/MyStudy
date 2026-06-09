

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
    List<List<Integer>>  leavels =new ArrayList<List<Integer>>();
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        helper(root,0);
        return leavels;
    }
    
    private void helper(TreeNode root,int level){
        if(null==root){
            return;
        }
        if(level == leavels.size()){
            leavels.add(0,new ArrayList<Integer>());
        }

        leavels.get(leavels.size()-level-1).add(root.val);

        if(root.left!=null){
            helper(root.left,level+1);
        }

        if(root.right!=null){
            helper(root.right,level+1);
        }
    }
}


只修改了两个地方：
1：list.add(0,new ArrayList<Integer>())
2: leavels.get(leavels.size()-level-1).add(root.val);