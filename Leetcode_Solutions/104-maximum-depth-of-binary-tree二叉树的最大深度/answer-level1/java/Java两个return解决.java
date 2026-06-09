    public int maxDepth(TreeNode root) {
    	if(root == null) return 0;
		return Math.max( root.left == null ? 0 : maxDepth(root.left), 
				root.right == null ? 0 :maxDepth(root.right) ) + 1 ;

    }