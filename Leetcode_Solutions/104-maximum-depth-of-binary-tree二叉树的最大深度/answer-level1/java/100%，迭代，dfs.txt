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
    public int maxDepth(TreeNode root) {
        return hp(root, 0);
    }

    private int hp(TreeNode r, int h) {
        if(r == null)
            return h;
        
        int hl = hp(r.left, h + 1);
        int hr = hp(r.right, h + 1);
        return hl > hr ? hl : hr;
    }
}
```
