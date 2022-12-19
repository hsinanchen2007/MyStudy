public TreeNode buildTree(int[] preorder, int[] inorder) {
        return build(preorder, inorder, 0, inorder.length - 1, 0, preorder.length - 1);
    }

    public TreeNode build(int[] preorder, int[] inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return null;
        }
        TreeNode treeNode = new TreeNode(preorder[preStart]);
        treeNode.left = null;
        treeNode.right = null;

        int middle = preorder[preStart];
        int inIndex = inStart;
        while (middle != inorder[inIndex]) {
            inIndex++;
        }
        int rightLength = inEnd - inIndex;
        int leflength = inIndex - inStart;
        if (leflength != 0) {
            treeNode.left = build(preorder, inorder, preStart + 1, preStart + leflength, inStart, inIndex - 1);
        }
        if (rightLength != 0) {
            treeNode.right = build(preorder, inorder, preStart + leflength + 1, preEnd, inIndex + 1, inEnd);
        }

        return treeNode;
    }