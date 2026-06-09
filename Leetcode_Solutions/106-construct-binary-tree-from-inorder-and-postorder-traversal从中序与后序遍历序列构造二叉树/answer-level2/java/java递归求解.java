```
public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder.length == 0 && postorder.length == 0) return null;
        
        TreeNode root = new TreeNode(postorder[postorder.length - 1]);
        int i = 0;
        for (i=0;i<inorder.length;i++) {
            if (inorder[i] == root.val) break;
        }
        int[] leftInorder = subArray(inorder, 0, new int[i], i);
        int[] rightInorder = subArray(inorder, i+1, new int[inorder.length-i-1], inorder.length-i-1);
        int[] leftPostorder = subArray(postorder, 0, new int[i], i);
        int[] rightPostorder = subArray(postorder, i, new int[postorder.length-i-1], postorder.length-i-1);
        root.left = buildTree(leftInorder, leftPostorder);
        root.right = buildTree(rightInorder, rightPostorder);
        
        return root;
    }

    private int[] subArray(int[] src, int start, int[] tar, int length) {
        System.arraycopy(src, start, tar, 0, length);
        return tar;
    }
```
