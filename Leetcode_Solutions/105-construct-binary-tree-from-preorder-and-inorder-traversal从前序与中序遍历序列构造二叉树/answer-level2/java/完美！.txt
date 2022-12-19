我真的太难了，写了一个小时。。。
```
public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTree(preorder, 0, preorder.length - 1,
                inorder, 0, inorder.length - 1);
    }

    public TreeNode buildTree(int[] preorder, int preLeft, int preRight,
                              int[] inorder, int inLeft, int inRight) {
        if (preLeft > preRight || inLeft > inRight) return null;
        TreeNode root = new TreeNode(preorder[preLeft]);

        int rootInd = 0;
        for (int i = inLeft; i <= inRight; i++) {
            if (inorder[i] == preorder[preLeft]) {
                rootInd = i;
                break;
            }
        }

        root.left = buildTree(preorder, preLeft + 1, preLeft + (rootInd-inLeft),
                inorder, inLeft,rootInd - 1);
        root.right = buildTree(preorder, preLeft + (rootInd - inLeft) + 1, preRight, 
                inorder, rootInd + 1, inRight);
        return root;
    }
```
