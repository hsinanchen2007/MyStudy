思路： 递归计算以左右子树根节点为起点的最长路径和，记为maxLeft和maxRight。由于最长路径可能不经过根节点，故用一个全局变量max记录总的最长路径。每次递归过程中，首先计算maxLeft和maxRight,并设置max为{max, root, maxLeft+root, maxRight+root, maxLeft+root+maxRight}这五个值中的最大值（因为maxLeft，maxRight以及root值都可能为负数，故需这样判断）。返回值设为{root, maxLeft+root, maxRight+root}这三个值中的最大值（因为返回值是包含根节点的最大值）。
```
class Solution {
    int max = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        traverse(root);
        return max;
    }

    public int traverse(TreeNode root) {
        if (root == null) return 0;
        int maxLeft = traverse(root.left);
        int maxRight = traverse(root.right);
        int mv = Math.max(maxLeft + root.val, maxRight + root.val);
        mv = Math.max(mv, root.val);
        max = Math.max(maxLeft + root.val + maxRight, max);
        max = Math.max(max, mv);
        return mv;
    }
}
```
