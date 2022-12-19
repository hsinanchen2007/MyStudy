### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] arr = new int[n][n];
        int[] row = {0, 1, 0, -1};
        int[] col = {1, 0, -1, 0};
        int r, c;
        r = 0;
        c = 0;
        int di = 0;
        for(int i = 1; i<=n*n; i++)
        {
            arr[r][c] = i;
            int dr = r + row[di%4];
            int dc = c + col[di%4];
            if(dr==n || dr<0 || dc==n || dc <0 || arr[dr][dc] != 0)
            {
                di++;
                dr = r + row[di%4];
                dc = c + col[di%4];
            }
            r = dr;
            c = dc;
        }
        return arr;
    }
}
```