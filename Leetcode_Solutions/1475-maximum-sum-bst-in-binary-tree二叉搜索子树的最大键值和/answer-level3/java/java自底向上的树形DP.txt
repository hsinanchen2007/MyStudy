本题是典型的自底向上的树形DP，与我在[打家劫舍III](https://leetcode-cn.com/problems/house-robber-iii/solution/zi-di-xiang-shang-de-shu-xing-dp-by-jackie-tien/)的题解本质上没有区别

```
  public int maxSumBST(TreeNode root) {
    return dfs(root).sumMax;
  }

  private State dfs(TreeNode root) {
    if (root == null) {
      return new State(true, Integer.MAX_VALUE, Integer.MIN_VALUE, 0, 0);
    }
    State leftState = dfs(root.left);
    State rightState = dfs(root.right);
    if (!leftState.isBST || !rightState.isBST || root.val <= leftState.maxValue || root.val >= rightState.minValue) {
      return new State(false, Integer.MIN_VALUE, Integer.MAX_VALUE, 0, Math.max(leftState.sumMax, rightState.sumMax));
    }
    int curMin = root.left == null ? root.val : leftState.minValue;
    int curMax = root.right == null ? root.val : rightState.maxValue;
    int sum = root.val + leftState.curSum + rightState.curSum;
    int maxSum = Math.max(sum, Math.max(leftState.sumMax, rightState.sumMax));
    return new State(true, curMin, curMax, sum, maxSum);
  }

  private static class State {
    boolean isBST;
    int minValue;
    int maxValue;
    int curSum;
    int sumMax;

    public State(boolean isBST, int minValue, int maxValue, int curSum, int sumMax) {
      this.isBST = isBST;
      this.minValue = minValue;
      this.maxValue = maxValue;
      this.curSum = curSum;
      this.sumMax = sumMax;
    }
  }
```
