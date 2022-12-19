**思路**
1、将左子树移到根节点的右子树上
2、找到左子树的最右边的节点，将其和根节点的右子树连接起来
3、如此递归
```
    public void flatten(TreeNode root) {
        if (root == null) return;
        if (root.left != null){
            TreeNode ll = root.left;
            while (ll.right != null){
                ll = ll.right;
            }
            ll.right = root.right;
            root.right = root.left;
            root.left = null;
        }
        flatten(root.right);
    }
```
