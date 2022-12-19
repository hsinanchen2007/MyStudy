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
    public TreeNode pruneTree(TreeNode root) {
        hasOne(root);
        return root;
    }

    boolean hasOne(TreeNode node){
        if(node == null){
            return false;
        }
        boolean left = false;
        boolean right = false;
        if(node.left != null){
            left = hasOne(node.left);
            //如果左子树没有值为1的子节点，那么将其置为null
            if(left == false){
                node.left = null;
            }
        }
        if(node.right != null){
            right = hasOne(node.right);
            //如果右子树没有值为1的子节点，那么将其置为null
            if(right == false){
                node.right = null;
            }
        }
        return node.val == 1 || left || right;
    }
}
```