```
    public boolean isValidBST(TreeNode root) {
        if (root == null) return true;
        ArrayList<Integer> list = new ArrayList<>();
        mid(root, list);
        for (int i = 0; i < list.size() - 1; i++) {
            if (list.get(i) >= list.get(i + 1)) return false;
        }
        return true;
    }

    //中序遍历
    void mid(TreeNode tree, List<Integer> res) {
        if (tree.left != null) mid(tree.left, res);
        res.add(tree.val);
        if (tree.right != null) mid(tree.right, res);
    }
```
