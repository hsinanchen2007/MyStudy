### 解题思路
当1的旁边有1个1，贡献周长4-1=(3)；有2个1，贡献周长4-2=(2)，有3个1，贡献周长4-3=(1);有4个1，贡献周长4-4=(0)。 
遍历每个1，统计四周1的个数。

### 代码

```java
class Solution {
    private int row;
    private int col;
    public int islandPerimeter(int[][] grid) {
        row = grid.length;
        if(row == 0) return 0;
        col = grid[0].length;
        int res = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    int cnt = 0;
                    cnt += count(grid, i+1, j);
                    cnt += count(grid, i-1, j);
                    cnt += count(grid, i, j+1);
                    cnt += count(grid, i, j-1);
                    res += 4 - cnt;
                }
            }
        }
        return res;
    }
    public int count(int[][] grid, int r, int c){
        if(r<0 || r>=row || c<0 || c>=col || grid[r][c]==0){
            return 0;
        }
        return 1;
    }
}
```