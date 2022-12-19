### 解题思路
最直接的解法，判断每个坐标是否可以到达且是否有路径到达
### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        int res = 1;
        int[][] count = new int[m][n];
        count[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 10 + i / 10 + j % 10 + j / 10 <= k &&
                        ((i - 1 >= 0 && count[i - 1][j] == 1) || 
                         (j - 1 >= 0 && count[i][j - 1] == 1) || 
                         (i + 1 < m && count[i + 1][j] == 1) || 
                         (j + 1 < n && count[i][j + 1] == 1))) {
                    res += 1;
                    count[i][j] = 1;
                }
            }
        }
        return res;
    }
}
```