```java
class Solution {
  public int[][] generateMatrix(int n) {
    int[][] result = new int[n][n];
    int val = 1;
    for (int i = 0; i < (int)Math.floor((n + 1) / 2); i++) {
      for (int j = i; j < n - i; i++) {
        // 四周终止位置
        int l = i, u = i, r = n - 1 - i, d = n - 1 - i;
        for (int _a = i; _a <= r; _a++) // 上
          result[u][_a] = val++;
        for (int _b = i + 1; _b <= d; _b++) // 右
          result[_b][r] = val++;
        for (int _c = r - 1; _c >= l; _c--) // 下
          result[d][_c] = val++;
        for (int _d = d - 1; _d > u; _d--) // 左
          result[_d][l] = val++;
      }
    }
    return result;
  }
}
```