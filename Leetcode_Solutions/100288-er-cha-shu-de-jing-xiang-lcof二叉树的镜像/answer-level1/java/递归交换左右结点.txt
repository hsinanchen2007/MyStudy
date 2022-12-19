递归交换左右结点
![截图.PNG](https://pic.leetcode-cn.com/1ad63d09c8fcb121d5d70f2b93cb0d35a1634110505248c5e9147a3366132f62-%E6%88%AA%E5%9B%BE.PNG)
```
    public TreeNode mirrorTree(TreeNode root) {
        switchLr(root);
        return root;
    }

    private void switchLr(TreeNode node) {
        if (node == null) {
            return;
        }
        TreeNode left = node.left;
        node.left = node.right;
        node.right = left;
        switchLr(node.left);
        switchLr(node.right);
    }
```
