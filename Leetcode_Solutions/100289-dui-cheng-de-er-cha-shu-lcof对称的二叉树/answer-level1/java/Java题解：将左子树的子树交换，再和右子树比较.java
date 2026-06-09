因为刚做完 相同的树 和 二叉树的镜像 两道题，所以很容易想到：将root左子树的左右子树递归交换，再和root的右子树比较，如果相同，说明该树是对称的。
```
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root == null) return true;
        return isSameTree(swapTree(root.left),root.right);
    }
    public TreeNode swapTree(TreeNode root) {
		//递归函数的终止条件，节点为空时返回
		if(root == null) {
			return null;
		}
		//下面三句是将当前节点的左右子树交换
		TreeNode tmp = root.right;
		root.right = root.left;
		root.left = tmp;
		//递归交换当前节点的 左子树
		swapTree(root.left);
		//递归交换当前节点的 右子树
		swapTree(root.right);
		//函数返回时就表示当前这个节点，以及它的左右子树
		//都已经交换完了
		return root;
	}
    public boolean isSameTree(TreeNode p, TreeNode q) {
		// p and q are both null
		if (p == null && q == null) return true;
		// one of p and q is null
		if (q == null || p == null) return false;
		if (p.val != q.val) return false;
		return isSameTree(p.right, q.right) &&
				isSameTree(p.left, q.left);
    }
}
```
