后序遍历最后一个是根节点，中序遍历中，根节点左边的是左子树，右边的是右子树
```
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return construct2(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1);
    }

    private TreeNode construct2(int[] inorder, int infrom, int into, int[] postorder, int postfrom, int postto) {
        if (infrom > into || postfrom > postto) {
            return null;
        }
        TreeNode root = new TreeNode(postorder[postto]);
        for (int i = infrom; i <= into; i++) {
            if (inorder[i] == postorder[postto]) {
                //注意左右子树分别的起始范围
                root.left = construct2(inorder, infrom, i - 1, postorder, postfrom, postfrom + i - infrom - 1);
                root.right = construct2(inorder, i + 1, into, postorder, postfrom + i - infrom, postto - 1);
            }
        }
        return root;
    }
```