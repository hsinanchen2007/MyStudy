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
    public TreeNode searchBST(TreeNode root, int val) {
        if(root==null||(root.left==null&&root.right==null&&root.val==val)){
            return root;
        }
   

        TreeNode result = root;
        boolean found  = false;
        while(result!=null){
            if(result.val>val){
                result = result.left;
            }else if(result.val<val){
                result = result.right;
            }else{
                found = true;
                break;
            }
        }
        if(!found){
            return null;
        }
        return result;
    }
}
```
