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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if(inorder==null || postorder==null || inorder.length==0 || postorder.length==0) return null;
        return buildTreeHelper(inorder,0,inorder.length-1,postorder,0,postorder.length-1);
    }

    public TreeNode buildTreeHelper(int[] inorder,int instart,int inend,int[] postorder,int poststart,int postend) {
        if(poststart > postend) return null;
        TreeNode root = new TreeNode(postorder[postend]);
        int rootValue = postorder[postend];
        int k = inend;
        while(k>=instart) {
            if(inorder[k] == rootValue) {
                break;
            }
            k--;
        }
        int rightlen = inend - k;
        root.left = buildTreeHelper(inorder,instart,k-1,postorder,poststart,postend - rightlen-1);
        root.right = buildTreeHelper(inorder,k+1,inend,postorder,postend - rightlen,postend-1);
        return root;
    }
}
```
