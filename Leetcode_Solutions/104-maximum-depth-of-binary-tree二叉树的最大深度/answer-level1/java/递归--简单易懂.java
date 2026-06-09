class Solution {
    public int maxDepth(TreeNode root) {
        return recTraversal(root,0);
    }

    public int recTraversal(TreeNode root, int deepth){
        if(null != root){
            return Math.max(recTraversal(root.right,deepth+1),recTraversal(root.left,deepth+1));
        }
        return deepth;
    }
}