```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        /* 使用 uint64_t，否则会发生个别测试用例数据溢出的问题 */
        uint64_t  path[obstacleGrid.size()][obstacleGrid[0].size()];
        int i ,j;

        if (obstacleGrid[0][0] == 1)
            return 0;
        else
            path[0][0] = 1;

        /* 处理边界第 0 行 */
        for (i = 1; i < obstacleGrid[0].size(); i++) {
            if (obstacleGrid[0][i] == 1 || obstacleGrid[0][i-1] == 1) {
                path[0][i] = 0;
                obstacleGrid[0][i] = 1;  /* 确保被设置为有障碍物 */
            }    
            else {
                path[0][i] = 1;
            }    
        }        

        /* 处理边界第 0 列 */
        for (i = 1; i < obstacleGrid.size(); i++) {
            if (obstacleGrid[i][0] == 1 || obstacleGrid[i-1][0] == 1) {
                path[i][0] = 0;
                obstacleGrid[i][0] = 1;  /* 确保被设置为有障碍物 */
            }    
            else {  
                path[i][0] = 1;    
            }    
        }

        for (i = 1; i < obstacleGrid.size(); i++) {
            for (j = 1; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j] == 1)
                    path[i][j] = 0;
                else
                    path[i][j] = path[i-1][j] + path[i][j-1]; 
            }
        }
        return path[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
```
