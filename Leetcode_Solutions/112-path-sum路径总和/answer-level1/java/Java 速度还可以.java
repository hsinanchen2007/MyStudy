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
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root==null){
            return false;
        }
        return hasPathSumR(root,sum);
    }
    
    private boolean hasPathSumR(TreeNode root, int sum){
        if(root==null){
            return false;
        }
        if(root.left==null&&root.right==null){
            if(sum!=root.val){
                return false;
            }else{
                return true;
            }
        }
        return hasPathSumR(root.left,sum-root.val)||hasPathSumR(root.right,sum-root.val);
    }
}
```
