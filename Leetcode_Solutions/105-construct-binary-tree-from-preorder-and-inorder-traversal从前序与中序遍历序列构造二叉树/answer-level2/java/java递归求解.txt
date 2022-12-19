```
public TreeNode buildTree(int[] preorder, int[] inorder) {

        if (preorder.length == 0 && inorder.length == 0) return null;

        TreeNode root = new TreeNode(preorder[0]);
        int i = 0;
        for (i=0;i<inorder.length;i++) {
            if (inorder[i] == preorder[0]) break;
        }

        int[] leftInorder = subArray(inorder, 0, new int[i], i);
        int[] rightInorder = subArray(inorder, i+1, new int[inorder.length-i-1], inorder.length-i-1);
        int[] leftPreOrder = subArray(preorder, 1, new int[i], i);
        int[] rightPreOrder = subArray(preorder, i+1, new int[preorder.length-i-1], preorder.length-i-1);

        root.left = buildTree(leftPreOrder, leftInorder);
        root.right = buildTree(rightPreOrder, rightInorder);

        return root;
    }

    private int[] subArray(int[] src, int start, int[] tar, int length) {
        System.arraycopy(src, start, tar, 0, length);
        return tar;
    }
```
