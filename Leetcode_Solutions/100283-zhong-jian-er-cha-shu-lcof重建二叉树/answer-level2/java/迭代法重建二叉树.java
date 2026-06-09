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
        return help(preorder,0,preorder.length-1,inorder,0,inorder.length-1);
    }

    /*ps,pe,is,ie对应都是数组的下标*/
    public TreeNode help(int[] preorder,int ps,int pe,int[] inorder,int is,int ie){
        if(preorder == null || inorder == null) return null;
        if(ps>pe) return null; //加上这一步，保证不会出现数组下标超限的问题
        int root_val = preorder[ps]; //求出根节点对应的值
        int i; //保存每一次循环对应的根节点下标
        for(i=is;i<=ie;i++){
            if(inorder[i] == root_val) break;
        }
        TreeNode root = new TreeNode(root_val);
        int left_len = i - is; //左子树的长度
        int right_len = ie - i;//右子树长度
        TreeNode left = help(preorder,ps+1,ps+1+left_len-1,inorder,is,i-1);
        TreeNode right = help(preorder,pe-right_len+1,pe,inorder,i+1,ie);
        root.left = left;
        root.right = right;
        return root;
    }
}