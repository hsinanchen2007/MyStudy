```
#define MAXSIZE 100
class Solution
{
public:
    long memory[MAXSIZE][MAXSIZE] = {0}; //! trivial in dp
    int dp_bottom_up(int m, int n, vector<vector<int>> &obstacleGrid)
    {
        for (size_t i = 1; i < m; i++)
        {
            for (size_t j = 1; j < n; j++)
            {
                memory[i][j] = obstacleGrid[i][j] ? 0 : (memory[i - 1][j] + memory[i][j - 1]);
            }
        }

        return memory[m - 1][n - 1];
    }
    int dp_up_down(int m, int n, vector<vector<int>> &obstacleGrid)
    {
        if (memory[m][n] < 0)
            memory[m][n] = obstacleGrid[m][n] ? 0 : dp_up_down(m - 1, n, obstacleGrid) + dp_up_down(m, n - 1, obstacleGrid);
        return memory[m][n];
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //* init dp
        for (size_t i = 0; i < m; i++)
            for (size_t j = 0; j < n; j++)
                memory[i][j] = -1; //* for up_down version

        memory[0][0] = !obstacleGrid[0][0];
        for (size_t i = 1; i < m; i++)
        {
            memory[i][0] = (memory[i - 1][0] == 0 || obstacleGrid[i][0]) ? 0 : 1;
        }
        for (size_t i = 1; i < n; i++)
        {
            memory[0][i] = (memory[0][i - 1] == 0 || obstacleGrid[0][i]) ? 0 : 1;
        }

        // return dp_bottom_up(m, n, obstacleGrid); //* 2-d DP
        return dp_up_down(m - 1, n - 1, obstacleGrid);
    }
};
```
