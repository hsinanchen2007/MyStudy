#define max(a, b) (a) > (b) ? (a) : (b)
int maxKilledEnemies(char** grid, int gridSize, int* gridColSize){
    
    int maxNumber = 0;
    for (int i = 0; i < gridSize; i++) {
        int colSize = gridColSize[i];
        for (int j = 0; j < colSize; j++) {
            //printf("%d %d, %c \n", i, j, grid[i][j]);
            if (grid[i][j] == '0') {
                //printf("%d %d", i, j);
                int cnt = 0;
                //第i -1行到0行，找敌人
                for (int k = i - 1; k >= 0; k--) {
                    if (grid[k][j] == 'E') {
                        cnt++;
                    } else if (grid[k][j] == 'W') {
                        break;
                    } 
                }
                // 第i+ 1到第gridSize行找敌人
                for (int k = i + 1; k < gridSize; k++) {
                    if (grid[k][j] == 'E') {
                        cnt++;
                    } else if (grid[k][j] == 'W') {
                        break;
                    } 
                }
                //第j -1列到0列，找敌人
                for (int k = j - 1; k >= 0; k--) {
                    if (grid[i][k] == 'E') {
                        cnt++;
                    } else if (grid[i][k] == 'W') {
                        break;
                    } 
                }
                // 第j + 1列到第colSize列找敌人
                for (int k = j + 1; k < colSize; k++) {
                    if (grid[i][k] == 'E') {
                        cnt++;
                    } else if (grid[i][k] == 'W') {
                        break;
                    } 
                }                
                
                maxNumber = max(maxNumber, cnt); 
            }
        }
        
    }
    return maxNumber;
}