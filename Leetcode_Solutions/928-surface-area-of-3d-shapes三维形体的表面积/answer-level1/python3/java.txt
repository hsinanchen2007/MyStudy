```
class Solution {
    int[][] dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    public int surfaceArea(int[][] grid) {
        int n = grid.length;
        int result = 0;
        int nval;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0) {
                    result += 2;
                }
                for(int k = 0; k < 4; k++) {
                    int ni = i + dir[k][0];
                    int nj = j + dir[k][1];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < n) {
                        nval = grid[ni][nj];
                    }
                    else {
                        nval = 0;
                    }
                    result += Math.max(0, grid[i][j] - nval);
                }
            }
        }
        return result;
    }
}
```
python3实现
```
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        n = len(grid)
        result = 0
        for i in range(n):
            for j in range(n):
                if grid[i][j]:
                    result += 2
                    for ni, nj in ((i-1,j),(i+1, j), (i, j-1), (i, j+1)):
                        if 0<=ni<n and 0<=nj<n:
                            nval = grid[ni][nj]
                        else:
                            nval = 0
                        result += max(grid[i][j] - nval, 0)
        return result
```
