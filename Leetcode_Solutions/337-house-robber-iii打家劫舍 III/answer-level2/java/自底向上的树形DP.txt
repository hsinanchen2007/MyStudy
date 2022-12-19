dp[0]表示当前节点不偷能获得的最大收益，dp[1]表示偷当前节点能获得的最大收益
```
  public int rob(TreeNode root) {
    int[] dp = dfs(root);
    return Math.max(dp[0], dp[1]);
  }

  public int[] dfs(TreeNode root) {
    if (root == null) return new int[2];
    int[] dp = new int[2];

    int[] left = dfs(root.left);
    int[] right = dfs(root.right);

    dp[0] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
    dp[1] = left[0] + right[0] + root.val;

    return dp;
  }
```
