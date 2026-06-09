//1. 从根节点开始遍历树
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        if (root == null) {
            return null;
        }
        TreeNode node = null;
        //2. 如果节点 p 和节点 q 都在左子树上，那么以左孩子为根节点继续 1 的操作
        if (isContainTreeNode(root.left, p) && isContainTreeNode(root.left, q)) {
            node = lowestCommonAncestor(root.left, p, q);
        }
        //3. 如果节点 p 和节点 q 都在右子树上，那么以右孩子为根节点继续 1 的操作
        if (isContainTreeNode(root.right, p) && isContainTreeNode(root.right, q)) {
            node = lowestCommonAncestor(root.right, p, q);
        }
        if (node != null) {
            return node;
        }
        //4. 如果条件 2 和条件 3 都不成立，这就意味着我们已经找到节 pp 和节点 qq 的 LCA 了
        return root;
    }

    //子方法：判断root节点中是否包含node节点
    public boolean isContainTreeNode(TreeNode root, TreeNode node) {
        if (root == null) {
            return false;
        }
        if (root == node) {
            return true;
        }
        return isContainTreeNode(root.left, node) || isContainTreeNode(root.right, node);
    }