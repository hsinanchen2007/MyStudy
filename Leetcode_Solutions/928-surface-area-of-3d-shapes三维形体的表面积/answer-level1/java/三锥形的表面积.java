### 解题思路
遍历每个格子，判断每个格子的上右下左方向是否贡献表面积。
Time O(n*2)
Space O(1)

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int s = 0;
        int n = grid.length;
        int[] di = {1, 0, -1, 0};
        int[] dj = {0, 1, 0, -1}; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 0)
                    s += 2;
                for(int t = 0; t < 4; t++){
                    int ci = i + di[t];
                    int cj = j + dj[t];
                    if(ci >= n || ci < 0 || cj >= n || cj < 0){
                        s += grid[i][j];
                    }else if(grid[i][j] - grid[ci][cj] > 0){
                        s += grid[i][j] - grid[ci][cj];
                    }
                }
            }
        }
        return s;
    }
}
```