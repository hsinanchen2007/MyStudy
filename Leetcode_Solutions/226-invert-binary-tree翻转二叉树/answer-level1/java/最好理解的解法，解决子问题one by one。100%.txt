class Solution {
    public TreeNode invertTree(TreeNode root) {
        if(root==null){return null;}
        invertTree(root,root.left,root.right);
        return root;
    }
    private void invertTree(TreeNode node,TreeNode left,TreeNode right){
        node.left=right;
        node.right=left;
        if(left!=null){
            invertTree(left,left.left,left.right);
        }
        if(right!=null){
            invertTree(right,right.left,right.right);
        }
       
    }
}