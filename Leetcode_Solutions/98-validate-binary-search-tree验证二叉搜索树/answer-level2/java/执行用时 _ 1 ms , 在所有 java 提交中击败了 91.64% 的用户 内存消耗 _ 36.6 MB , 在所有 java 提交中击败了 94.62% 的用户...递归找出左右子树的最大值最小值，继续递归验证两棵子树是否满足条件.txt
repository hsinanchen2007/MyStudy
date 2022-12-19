
class Solution {
    public boolean isValidBST(TreeNode root) {
        if(root==null)return true;
        if(root.left==null&&root.right==null) return true;
        if(root.left==null) return min(root.right)>root.val&&isValidBST(root.right);
        if(root.right==null) return max(root.left)<root.val&&isValidBST(root.left);
        return max(root.left)<root.val&&min(root.right)>root.val&&isValidBST(root.right)&&isValidBST(root.left);
    }
    public int max(TreeNode root){
        if(root.right==null) return root.val;
        return max(root.right);
    }
    public int min(TreeNode root){
        if(root.left==null) return root.val;
        return min(root.left);
    }
}