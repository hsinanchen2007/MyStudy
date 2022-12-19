```
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode p = root.left;
        root.left = invertTree(root.right);
        root.right = invertTree(p);
        return root;
    }
}
```

执行耗时:0 ms,击败了100.00% 的Java用户
		内存消耗:34.1 MB,击败了40.25% 的Java用户
递归，左边暂存，左变右，右边再变左边

