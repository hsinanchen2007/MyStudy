1. 二分搜索树的左右子树也一定是二分搜索树，所以可以用递归解决。

2. 二分搜索树的左子树的所有值必须小于节点值，右子树的所有值必须大于节点值，所以可以递归传入最小值和最大值范围，来收缩判断。

3. 空树是一个二分搜索树。

想清楚这三个条件，就可以写出合适的递归代码。


```
class Solution {
    public boolean isValidBST(TreeNode root) {
        return isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    public boolean isValidBST(TreeNode node, long min, long max) {
        if (node == null) return true;
        if (node.val <= min || node.val >= max) return false;
        return isValidBST(node.left, min, Math.min(max, node.val)) && isValidBST(node.right, Math.max(min, node.val), max);
    }
}
```
