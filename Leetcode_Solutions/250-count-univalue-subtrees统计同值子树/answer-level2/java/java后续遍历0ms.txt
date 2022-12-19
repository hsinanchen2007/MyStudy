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
 // 后续遍历
class Solution {
    public int count = 0;
    public int countUnivalSubtrees(TreeNode root) {
        if(root==null) return count;
        countUnivalSubtreesHelper(root);
        return count;
    }
    public boolean countUnivalSubtreesHelper(TreeNode root) {
        if(root==null) return true;
        boolean left = countUnivalSubtreesHelper(root.left);
        boolean right = countUnivalSubtreesHelper(root.right);
        if(left && right) {
            if(root.left!=null && root.left==null) {
                count++;
                return true;
            }else if(root.left!=null && root.val!=root.left.val) {
                return false;
            }else if(root.right!=null && root.val!=root.right.val) {
                return false;
            }else {
                count++;
                return true;
            }
        }
        return false;
    }
}
```
