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
       return buildTree(preorder,0,preorder.length-1,inorder , 0, inorder.length-1) ;
    }

    public TreeNode buildTree(int[] preorder,int pstart , int pend , int[] inorder, int istart , int iend) {
        if (pstart <= pend && istart <= iend) {
            TreeNode parent = new TreeNode(preorder[pstart]) ;
            int iMidIndex = istart ;
            for (int i = istart ;i <= iend ; i++) {
                if (inorder[i]==preorder[pstart]){
                        iMidIndex = i ;
                        break ;
                }
            }
            int leftNum = iMidIndex - istart  ;
            parent.left = buildTree(preorder,pstart+1,pstart+leftNum ,inorder ,istart,iMidIndex-1) ;
            parent.right = buildTree(preorder,pstart + leftNum + 1,pend ,inorder ,iMidIndex+1,pend ) ;
            return parent ;
        }else
            return null ;
    }
}
```
