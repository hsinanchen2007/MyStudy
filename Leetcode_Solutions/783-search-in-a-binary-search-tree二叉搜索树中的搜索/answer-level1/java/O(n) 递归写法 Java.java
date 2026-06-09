根据算法导论上的二叉搜索树的搜索伪码来实现，首先，一棵树为空或者它的节点不存在，那就直接return null就好了，
如果根节点等于值，那就return以这个根节点的子树就好了，最后利用递归来分别遍历该树的左右子树。
```
 public TreeNode searchBST(TreeNode root, int val) {
        if (root == null || val == 0) return null;
        if (root.val == val) return root;
        if (val < root.val) return searchBST(root.left,val);
        else return searchBST(root.right,val);
    }
```