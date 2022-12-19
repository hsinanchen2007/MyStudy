根据preorder的start找到根, 然后根据inorder确定左右子树关系。


    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTreeHelper(preorder,inorder,0,inorder.length-1,0,preorder.length-1);
    }

    private TreeNode buildTreeHelper(int[] preoder, int[] inorder, int in_order_start, int in_order_end,
        int pre_order_start, int pre_order_end){

        if(in_order_start > in_order_end || pre_order_start > pre_order_end){
            return null;
        }
        int v = preoder[pre_order_start];
        int rootIndex = findIndex(inorder,v);
        int gap = rootIndex - in_order_start;
        TreeNode r = new TreeNode(v);
        r.left = buildTreeHelper(preoder,inorder, in_order_start,rootIndex-1,
                pre_order_start+1,pre_order_start+gap);

        r.right = buildTreeHelper(preoder,inorder,rootIndex+1,in_order_end,
                pre_order_start+gap+1,pre_order_end);

        return r;

    }

    private int findIndex(int[] inorder,int target){
        for (int i = 0; i < inorder.length; i++) {
            if(inorder[i] == target){
                return i;
            }
        }
        return -1;
    }
