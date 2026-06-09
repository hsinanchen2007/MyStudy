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
    int result = 200;
    int last = -100; 
    public int minDiffInBST(TreeNode root) {
        if(root == null){
            return 0;
        }
        minDiffInBSTCore(root);
        return result;
    }

    void minDiffInBSTCore(TreeNode node){
        if(node.left != null){
            minDiffInBSTCore(node.left);
        }
        int temp = node.val - last;
        if(temp < result){
            result = temp;
        }
        last = node.val;
        if(node.right != null){
            minDiffInBSTCore(node.right);
        }

    }
}
```