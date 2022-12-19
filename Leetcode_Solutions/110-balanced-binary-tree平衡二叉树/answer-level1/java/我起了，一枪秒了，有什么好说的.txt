    public int getHeight(TreeNode treeNode){
        if (treeNode==null) return 0;
        return Math.max(getHeight(treeNode.left)+1,getHeight(treeNode.right)+1);
    }
    public boolean isBalanced(TreeNode root) {
        if(root==null) return true;
        return Math.abs(getHeight(root.right)-getHeight(root.left))>1?false:isBalanced(root.right)&&isBalanced(root.left);
    }