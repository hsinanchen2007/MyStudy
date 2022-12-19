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
    TreeNode leftNode;
    TreeNode rightNode;
    TreeNode lastNode;
    int last = Integer.MIN_VALUE;
    public void recoverTree(TreeNode root) {
        recoverTreeCore(root);
        int temp = leftNode.val;
        leftNode.val = rightNode.val;
        rightNode.val = temp;
    }
    
    void recoverTreeCore(TreeNode root){
        if(root.left != null){
            recoverTreeCore(root.left);
        }
        if(root.val < last){
            if(leftNode == null){
                leftNode = lastNode;
                rightNode = root;
            } else {
                rightNode = root;
            }
        }
        last = root.val;
        lastNode = root;
        if(root.right != null){
            recoverTreeCore(root.right);
        }
    }
}
```