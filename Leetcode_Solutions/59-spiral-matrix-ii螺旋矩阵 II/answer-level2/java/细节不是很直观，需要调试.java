### 解题思路
不是很直观，需要调试

### 代码

```java
class Solution {
    public int[][] generateMatrix(int n) {
         int[][] res = new int[n][n];
        int t = 0, r = n - 1, b = n - 1, l = n - 1;
        int num = 1;
        while (num <= n * n) {
            //上侧移动
            for (int i = t; i < n - t; i++)
                res[t][i] = num++;
            t++;
//            右侧移动
            for (int i = n - r; i <= r; i++)
                res[i][r] = num++;
            r--;
            //下侧移动
            for (int i = b - 1; i >= n - b - 1; i--)
                res[b][i] = num++;
            b--;
            //左侧移动
            for (int i = l - 1; i >= n - l; i--)
                res[i][n - l - 1] = num++;
            l--;
        }
        return res;
    }
}
```