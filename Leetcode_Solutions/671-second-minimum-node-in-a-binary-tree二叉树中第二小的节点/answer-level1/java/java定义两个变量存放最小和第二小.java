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
    
    int one = -2;   //第一小
    int two = -1;   //第二小
    public int findSecondMinimumValue(TreeNode root) {
        if(root == null) return -1;
        helper(root);
        if(two == -2)
            return -1;
        return two;
    }
    public void helper(TreeNode root){
        if(root == null) return;
        
         if(one == -2){
            one = root.val;
        }else if(two == -1){
             if(root.val > one)
             two = root.val;
             else if(root.val != one){
             two = one;
             one = root.val;
             }
         }
        if(root.val < one){
            two = one;
            one = root.val;
        }else if(root.val > one && root.val < two){
             two = root.val;
        }
        helper(root.left);
        helper(root.right);
        
    }
}
```
