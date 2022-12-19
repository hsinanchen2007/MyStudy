#define MIN(A, B) ((A) < (B) ? (A) : (B))

int minPathSum(int** grid, int gridSize, int* gridColSize){

    int dp[gridSize][*gridColSize];
    
    dp[0][0] = grid[0][0];

    for (int i = 1; i < *gridColSize; i++) {
        dp[0][i] = grid[0][i] + dp[0][i-1];
    }
    for (int i = 1; i < gridSize; i++) {
        dp[i][0] = grid[i][0] + dp[i-1][0];
    }
    for (int i = 1; i < gridSize; i++) {
        for (int j = 1; j < *gridColSize; j++) {
            dp[i][j] = grid[i][j] + MIN(dp[i][j-1], dp[i-1][j]);
        }
    }

    return dp[gridSize-1][*gridColSize-1];
}