dfs返回数组ans，ans[0]表示是否是bst，ans[1]表示当前子树最小值，ans[2]表示当前子树最大值.
```
class Solution {
    public boolean isValidBST(TreeNode root) {
        int[] ans = dfs(root);
        return ans[0] == 1;
    }

    int[] dfs(TreeNode root) {
        if (root == null) return new int[] {1, -1, -1};
        int min = root.val, max = root.val;
        if (root.left != null) {
            int[] ans = dfs(root.left);
            if (ans[0] == 0 || ans[2] >= root.val) return new int[] {0, -1, -1};
            min = ans[1];
        }
        if (root.right != null) {
            int[] ans = dfs(root.right);
            if (ans[0] == 0 || ans[1] <= root.val) return new int[] {0, -1, -1};
            max = ans[2];
        }
        return new int[] {1, min, max};
    }
}
```