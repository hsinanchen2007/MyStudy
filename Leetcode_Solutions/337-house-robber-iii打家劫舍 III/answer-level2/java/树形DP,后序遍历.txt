```
class Solution {
    public int rob(TreeNode root) {
        int[] res = dfsRob(root);
        return Math.max(res[0], res[1]);
    }
    public int[] dfsRob(TreeNode root) {
        if (root == null) return new int[]{0,0};
        int[] left = dfsRob(root.left);
        int[] right = dfsRob(root.right);
        int temp1 = left[0] + right[0] + root.val;
        int temp2 = left[1] + right[0];
        temp2 = Math.max(temp2, left[0] + right[1]);
        temp2 = Math.max(temp2, left[1] + right[1]);
        temp2 = Math.max(temp2, left[0] + right[0]);
        return new int[]{temp2, temp1};
    }
}
```
