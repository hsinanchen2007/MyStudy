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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder==null || preorder.length==0 || inorder==null || inorder.length==0) return null;
        return buildTreeHelper(preorder,0,preorder.length-1,inorder,0,inorder.length-1);
    }

    private TreeNode buildTreeHelper(int[] preorder,int prestart,int preend,int[] inorder,
        int instart,int inend) {
            if(prestart>preend) {
                return null;
            }
            int i=instart;
            int rootValue = preorder[prestart];
            while(i<=inend) {
                if(rootValue == inorder[i]) {
                    break;
                }
                i++;
            }
            int leftlen = i - instart;
            TreeNode root = new TreeNode(rootValue);
            root.left = buildTreeHelper(preorder,prestart+1,prestart+leftlen,inorder,instart,i-1);
            root.right = buildTreeHelper(preorder,prestart+leftlen+1,preend,inorder,i+1,inend);
            return root;
        }
}
```
