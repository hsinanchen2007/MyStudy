使用动态规划解题，用二维数组存储所需要的最少的现金数
```
class Solution {
    public int getMoneyAmount(int n) {
        // 横坐标代表范围的起始值， 纵坐标代表范围的最大值
        int[][] record = new int[n + 2][n + 2];
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 1; j--) {
                // 从纵坐标开始递推，需要遍历所有组合来确定最小值
                int min = Integer.MAX_VALUE;
                for (int l = j; l <= i; l++) {
                    int temp = l + Math.max(record[j][l - 1], record[l + 1][i]);
                    if (min > temp) {
                        min = temp;
                    }
                }
                record[j][i] = min;
            }
        }
        return record[1][n];
    }
}
```
