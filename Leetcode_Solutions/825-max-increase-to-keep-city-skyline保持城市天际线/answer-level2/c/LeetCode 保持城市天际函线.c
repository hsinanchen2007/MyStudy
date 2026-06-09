
}```
int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
    
    int colMaxes[gridSize], rowMaxes[gridSize]; 
    for(int i=0; i<gridSize; i++){
        colMaxes[i] = 0;
        rowMaxes[i] = 0;
    }
    
    for(int i = 0; i < gridSize; i++){
        for(int j =0; j < gridSize; j++){
            if( colMaxes[i] < grid[j][i])
                colMaxes[i] = grid[j][i];
            if( rowMaxes[i] < grid[i][j])
                rowMaxes[i] = grid[i][j];
        }
    }
    
    int ans = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridSize; j++){
            int temp = rowMaxes[i] < colMaxes[j] ? rowMaxes[i] : colMaxes[j];
            ans += (temp - grid[i][j]);
        }
    }
    
    return ans;


代码块
```
