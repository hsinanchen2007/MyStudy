```
//以root为根的树中同值子树个数
public int countUnivalSubtrees(TreeNode root) {
    if (root == null) {
        return 0;
    }
    //root本身是否同值+左子树同值子树个数+右子树同值子树个数
    return (isSubtreeUnival(root) ? 1 : 0) + countUnivalSubtrees(root.left)
            + countUnivalSubtrees(root.right);
}

//以root为根的树中所有节点是否值相同
boolean isSubtreeUnival(TreeNode root) {
    if (root == null) {
        return true;
    }
    //和左子树根节点判断同值
    if (root.left != null && root.val != root.left.val) {
        return false;
    }
    //和右子树根节点判断同值
    if (root.right != null && root.val != root.right.val) {
        return false;
    }
    //递归
    return isSubtreeUnival(root.left) && isSubtreeUnival(root.right);
}
```
