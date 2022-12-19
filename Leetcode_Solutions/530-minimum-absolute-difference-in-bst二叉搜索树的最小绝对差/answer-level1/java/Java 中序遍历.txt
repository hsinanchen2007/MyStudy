**我的[leetcode解题集](https://github.com/JuiceZhou/Leetcode)，求小星星呀(๑•̀ㅂ•́)و✧**

思路：

BST中序遍历是升序，所以遍历时求相邻两个节点之间的最小绝对差值即可

```
TreeNode pre = null;
int res = Integer.MAX_VALUE;

public int getMinimumDifference(TreeNode root) {
    if (root == null) return 0;
    helper(root);
    return res;
}

private void helper(TreeNode root) {
    if (root == null) return;
    helper(root.left);
    if (pre != null) {
        //求相邻节点的差值
        res = Math.min(res, Math.abs(root.val - pre.val));
    }
    pre = root;
    helper(root.right);
}
```
