

    public TreeNode mirrorTree(TreeNode root) {

        if(root != null){

            TreeNode tempNode = root.left;
            root.left = root.right;
            root.right = tempNode;

            mirrorTree(root.left);
            mirrorTree(root.right);

        }
        return root;
    }
