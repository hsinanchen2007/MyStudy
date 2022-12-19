```
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) return false;
        return back (root, sum);
    }
    private boolean back(TreeNode root, int sum){
        //为null 表示当前子树没有结果
        if (root == null) return false;
        //当叶子节点时, 比较当前值和剩余的值是否相等
        if (root.left == null && root.right == null) {
            return root.val == sum;
        }
        //左子树有结果 或者 右子树有结果
        return back(root.left, sum-root.val) || back(root.right, sum - root.val);
    }
}
```
