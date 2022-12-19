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
    List<Integer> inOrderList = new ArrayList<>();
    public boolean isValidBST(TreeNode root) {
        if(root == null) return true;
        inOrderHelper(root);
        
        for(int i=0;i<inOrderList.size()-1;i++){
        if(inOrderList.get(i+1)<=inOrderList.get(i)) return false;//must be <=
         }
    return true;

        
    }
    private void inOrderHelper(TreeNode root){
        if(root == null) return;
        inOrderHelper(root.left);
        inOrderList.add(root.val);
        inOrderHelper(root.right);
    }
}
```