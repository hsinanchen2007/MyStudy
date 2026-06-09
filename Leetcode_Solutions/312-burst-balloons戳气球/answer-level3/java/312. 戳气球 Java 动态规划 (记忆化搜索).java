### 代码

```java
/**
 * 动态规划
 * 定义状态: f[i][j] 表示戳破 [i, j] 区间的气球能得到的最大收益
 * 状态转移: f[i][j] = max{ f[i][k-1] + f[k+1][j] + a[i-1]*a[k]*a[j+1] }
 *          决策是这个区间最后一个戳破的是哪个气球
 *          为什么要倒着思考? 因为正着不好思考 (戳破一个气球相邻关系就改变了)
 */
class Solution {

    int n;
    int[] nums;
    int[][] f;
    
    private int stab(int k, int i, int j) {
        int left = i == 0 ? 1 : nums[i - 1];
        int right = j == n - 1 ? 1 : nums[j + 1];
        return left * nums[k] * right;
    }

    private int dp(int i, int j) {
        if (i > j) {
            return 0;
        }
        if (f[i][j] >= 0) {
            return f[i][j];
        }
        f[i][j] = 0;
        for (int k = i; k <= j; k++) {
            f[i][j] = Math.max(f[i][j], dp(i, k - 1) + dp(k + 1, j) + stab(k, i, j));
        }
        return f[i][j];
    }

    public int maxCoins(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        n = nums.length;
        this.nums = nums;
        f = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(f[i], -1); // f[i][j] 可能出现 0, 所以用 -1 表示还未计算过
        }
        return dp(0, n - 1);
    }
}

```