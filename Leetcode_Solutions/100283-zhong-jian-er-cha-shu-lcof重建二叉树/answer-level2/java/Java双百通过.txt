int inIndex=0;
    int preIndex=0;
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return helper(preorder,inorder,(long)Integer.MAX_VALUE+1);
    }
    public TreeNode helper(int[] preorder,int[] inorder,long stop){
        if(preIndex>=preorder.length){
            return null;
        }
        if(inorder[inIndex]==stop){
            preIndex++;
            return null;
        }
        int val=preorder[preIndex++];
        TreeNode root=new TreeNode(val);
        root.left=helper(preorder,inorder,val);
        root.right=helper(preorder,inorder,stop);
        return root;
    }