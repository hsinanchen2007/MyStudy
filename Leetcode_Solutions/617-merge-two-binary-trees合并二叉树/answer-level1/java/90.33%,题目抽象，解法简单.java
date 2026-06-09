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
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        // very clear
        if(t1 == null && t2 == null)
            return null;
        TreeNode nr = new TreeNode(0);
        if(t1 == null) {
            nr.val = t2.val;
            nr.left = mergeTrees(null, t2.left);
            nr.right = mergeTrees(null, t2.right);
        }
        else if(t2 == null) {
            nr.val = t1.val;
            nr.left = mergeTrees(t1.left, null);
            nr.right = mergeTrees(t1.right, null);
        }
        else {
            nr.val = t1.val + t2.val;
            nr.left = mergeTrees(t1.left, t2.left);
            nr.right = mergeTrees(t1.right, t2.right);
        }
        return nr;
    }


}
```
