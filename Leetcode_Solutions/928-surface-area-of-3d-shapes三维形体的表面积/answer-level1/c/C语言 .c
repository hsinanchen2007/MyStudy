![三锥形体的表面积.PNG](https://pic.leetcode-cn.com/9059425e9e580a04327864492dd89b84b2df82c98eb8507afdcedb627e94df09-%E4%B8%89%E9%94%A5%E5%BD%A2%E4%BD%93%E7%9A%84%E8%A1%A8%E9%9D%A2%E7%A7%AF.PNG)

int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int res = 0;
    int row = gridSize;
    int col = *gridColSize;
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] > 0) {
                res += (grid[i][j] * 4 + 2);
                 
            }
             if (i - 1 >= 0 && grid[i - 1][j] > 0) {
                    res -= grid[i - 1][j] < grid[i][j] ? grid[i - 1][j] : grid[i][j];
                }
                
                if (i + 1 < row && grid[i + 1][j] > 0) {
                    res -= grid[i + 1][j] < grid[i][j] ? grid[i + 1][j] : grid[i][j];
                }
                if (j - 1 >= 0 && grid[i][j - 1] > 0) {
                    res -= grid[i][j - 1] < grid[i][j] ? grid[i][j- 1] : grid[i][j];
                }
                if (j + 1 < col && grid[i][j + 1] > 0) {
                    res -= grid[i][j + 1] < grid[i][j] ? grid[i][j + 1] : grid[i][j];
                }  
            
        }
    }
    
    return res;

}