
要判断 二叉树是对称，可以把问题先分解为两步
- 当前节点是否对称
- 当前节点的左右节点是否对称
![微信截图_20200221153828.jpg](https://pic.leetcode-cn.com/073fe743cf4dc4fa58d97941c0002ea0ab0a5ef7c2dd606fd7c77ee0827fe411-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200221153828.jpg)
那问题又变成了左右节点是否对称
- 当前节点的左节点为空，当前节点的右节点为空，对称，返回true
- 当前节点的左节点或者右节点为空，不对称，返回false
- 当前节点的左节点不为空，当前节点的右节点不为空，这里就不要判断是否为空了，因为上面小两步已经为我们过滤掉为空的情况。所以
  这里要判断是的，当前节点的左节的值与当前节点的右节的值是否相等，不相等的话返回false
- 接下来看这个图
![微信截图_20200221155614.jpg](https://pic.leetcode-cn.com/24c5feb56987adf6a42d8b5c0ccb1ea7a9af78f34fc6c9d69e8c432c3339ba49-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200221155614.jpg)

通过上面两小步，就返回，（左节点的左节点与右节点的右节点 ） 与上 （左节点的右节点与右节点的左节点）

```
    public boolean isSymmetric(TreeNode root) {
        if (root == null) return true;
        return isSymmetric(root.left, root.right);
    }

    private boolean isSymmetric(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) return true;
        if (t1 == null || t2 == null) return false;
        if (t1.val != t2.val) return false;
        return isSymmetric(t1.left, t2.right) && isSymmetric(t1.right, t2.left);
    }
```
有错误的话，希望大家指出。
