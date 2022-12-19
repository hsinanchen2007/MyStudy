### 解题思路
每个点只需要考虑他上面和左面的条数就行，累加到最后就是结果

### 代码

```java
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] a = new int[n][m];
        int b = 0;
        while (b < n) {
            int c = 0;
            while (c < m) {
                if (c == 0 || b == 0) {
                    a[b][c] = 1;
                } else {
                    a[b][c] = a[b - 1][c] + a[b][c - 1];
                }
                c++;
            }
            b++;
        }
        return a[n - 1][m - 1];
    }
}
```