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
    public int preIndex = 0;
    public TreeNode buildTreeChild(int[] postorder,  
                                   int[] inorder, int inbegin, int inend) {
        TreeNode root = new TreeNode(postorder[preIndex]);
        int count = -1;
        for(int i = inend;i >= inbegin;i--){
            if(postorder[preIndex] == inorder[i]){
                count = i;
                break;
            }
        }
        if(count == -1){
            return null;
        }
        preIndex--;
        root.left = null;
        root.right = null;
        if(count + 1 <= inend){  
            TreeNode right = buildTreeChild(postorder,inorder,count + 1,inend);
            root.right = right;
        }
        if(inbegin <= count - 1){
            TreeNode left = buildTreeChild(postorder,inorder,inbegin,count - 1);
            root.left = left;
        }
        return root;
    }
   public TreeNode buildTree(int[] inorder, int[] postorder) {
        if(postorder.length == 0 || inorder.length == 0){
            return null;
        }
        preIndex = postorder.length - 1;
        return buildTreeChild(postorder,inorder,0,inorder.length - 1);  
        
    }
    
}

```
