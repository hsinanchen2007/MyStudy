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
    public boolean isSymmetric(TreeNode root) {

        if(root==null)
        return true;
        // 注意此处传引用问题, 故代入根节点的左树与右树进行比较
        return Symmetricornot(Symmetric(root.left),root.right); 
      
    }

    public TreeNode Symmetric(TreeNode root)
    {
        if(root==null)
        return null;

        TreeNode tmp=root.left;
        root.left=root.right;
        root.right=tmp;

        Symmetric(root.left);
        Symmetric(root.right);

        return root;

    }

    public boolean Symmetricornot(TreeNode root, TreeNode sym)
    {
        if((root==null)&&(sym==null))
        return true;
        
        if((root==null)||(sym==null))
        return false;
       
        if(sym.val!=root.val)
        return false;

        return Symmetricornot(root.left,sym.left)&&Symmetricornot(root.right,sym.right); 
        
    }


}
```
