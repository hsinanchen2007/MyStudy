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

import java.util.Arrays;

class Solution {
    public TreeNode bstFromPreorder(int[] preorder) {
        TreeNode root = new TreeNode(preorder[0]);

        if (preorder.length == 1) {
            return root;
        }
        
        int c = 0;
        
        for (int i = 1; i < preorder.length; i++) {
            if (preorder[i] > root.val) {
                c = i;
                break;
            }
        }
        
        if (c == 0) {
            root.left = bstFromPreorder(Arrays.copyOfRange(preorder, 1, preorder.length));
            root.right = null;
        }else if (c == 1) {
            root.left = null;
            root.right = bstFromPreorder(Arrays.copyOfRange(preorder, 1, preorder.length));
        }else{
            root.left = bstFromPreorder(Arrays.copyOfRange(preorder, 1, c));
            root.right = bstFromPreorder(Arrays.copyOfRange(preorder, c, preorder.length));
        }

        return root;
    }
}
```
