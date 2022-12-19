```
执行用时 : 0 ms , 在所有 C 提交中击败了 100.00% 的用户 内存消耗 : 5.7 MB , 在所有 C 提交中击败了 100.00% 的用户
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    //不能直接使用公式求解 使用动态规划求解
    

    long int i, j;

    long int ** path = (long int **)malloc(sizeof(long int *) * obstacleGridSize);
    for(i = 0; i < obstacleGridSize; ++ i){
        path[i] = (long int *)malloc(sizeof(long int) * (* obstacleGridColSize));
    }
    
    if(obstacleGrid[0][0] == 0){
        path[0][0] = 1;
    }else{
        return 0;
    }
    
    for(i = 1; i < obstacleGridSize; ++ i){                
        if(obstacleGrid[i][0] == 0 && path[i - 1][0] == 1){
            path[i][0] = 1;
        }else{
            path[i][0] = 0;
        }
    }

    for(j = 1; j < *obstacleGridColSize; ++ j){                
        if(obstacleGrid[0][j] == 0 && path[0][j - 1] == 1){
            path[0][j] = 1;
        }else{
            path[0][j] = 0;
        }
    }

    for(i = 1; i < obstacleGridSize; ++ i){        
        for(j = 1; j < *obstacleGridColSize; ++ j){
            if(obstacleGrid[i][j] == 0){
                path[i][j] = path[i-1][j] + path[i][j-1];
            }else{
                path[i][j] = 0;
            }        
        }        
    }

    return path[obstacleGridSize - 1][*obstacleGridColSize - 1];
}
```
