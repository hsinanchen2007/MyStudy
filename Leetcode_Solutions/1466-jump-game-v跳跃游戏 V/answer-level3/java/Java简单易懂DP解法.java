```
class Solution {
    public int maxJumps(int[] arr, int d) {
        int n = arr.length;
        Integer[] idx = new Integer[n];
        for (int i = 0; i < n ; i++) {
            idx[i] = i;
        }
        // 先把柱子从矮到高排序，并记录索引
        Arrays.sort(idx, (Comparator) (o1, o2) -> arr[(Integer) o1] - arr[(Integer) o2]);

        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        int res = 0;
        for (int ii = 0; ii < n; ii++) {
            int i = idx[ii];
            // 往左边跳
            for (int j = i - 1; j >= 0 && j >= i - d; j--) {
                if (arr[j] >= arr[i]) break;
                dp[i] = Math.max(dp[j] + 1, dp[i]);
            }
            // 往右边跳
            for (int j = i + 1; j < n && j <= i + d; j++) {
                if (arr[j] >= arr[i]) break;
                dp[i] = Math.max(dp[j] + 1, dp[i]);
            }
            res = Math.max(res, dp[i]);
        }
        return res;
    }
}
```
