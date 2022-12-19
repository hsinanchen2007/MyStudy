

因为二叉搜索树的左子树<根<右子树的性质，按right-root-left的顺序遍历很容易求出累加和

```
 int add = 0;

    public TreeNode convertBST(TreeNode root) {
        if (root == null) return root;
        convertBST(root.right);
        root.val += add;
        add = root.val;
        convertBST(root.left);
        return root;
    }
```
