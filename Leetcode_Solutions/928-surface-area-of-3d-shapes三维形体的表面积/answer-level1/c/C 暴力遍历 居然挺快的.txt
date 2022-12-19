int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int sum = 0;
    int nextR;
    int nextC;
    int direct[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridSize; j++){
            if(grid[i][j] > 0){
                sum += 2;
                for (int k = 0; k < 4; k++){
                    nextR = i + direct[k][0];
                    nextC = j + direct[k][1];
                    if(nextR >= 0 && nextR < gridSize && nextC >= 0 && nextC < gridSize){
                        if (grid[nextR][nextC] < grid[i][j]){
                            sum += grid[i][j] - grid[nextR][nextC];
                        }
                    } else {
                        sum += grid[i][j];
                    }
                }
            }
        }
    }
    return sum;
}