### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] Arr = new int[m][n];
        Arr[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                Arr[i][j] = Arr[i - 1 < 0 ? i : i - 1][j] + Arr[i][j - 1 < 0 ? j : j - 1];
            }
        }
        return Arr[m - 1][n - 1];
    }
}
```