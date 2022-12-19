```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //dp
        if(obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<long int>> path(row,vector<long int>(col,0));
        
        for(int i = 0;i < col;++i){
            if(obstacleGrid[0][i] == 0)
                path[0][i] = 1;
            else
                break;
        }
        for(int j = 0;j < row;++j){
            if(obstacleGrid[j][0] == 0)
                path[j][0] = 1;
            else
                break;
        }
        
        for(int i = 1;i < row;++i)
        {
            for(int j = 1;j < col;++j)
            {
                if(obstacleGrid[i][j] == 1)
                    path[i][j] = 0;
                else
                    path[i][j] = path[i][j-1] + path[i-1][j];
            }
        }
        return path[row-1][col-1];
    }
};
```
