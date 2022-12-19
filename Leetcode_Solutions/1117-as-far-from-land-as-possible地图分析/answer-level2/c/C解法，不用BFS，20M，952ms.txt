**思路**
直接记录1和0的坐标，然后循环进行查找。

```
```
int maxDistance(int** grid, int gridSize, int* gridColSize){
    int row = gridSize;
    int col = *gridColSize;
    int dis = -1;
    int numOne = 0, numZero = 0;
    int **mapOne;
    int **mapZero;
    mapOne = (int **)malloc(row * col * sizeof(int *));
    mapZero = (int **)malloc(row * col * sizeof(int *));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == 1) {
                mapOne[numOne] = (int *)malloc(2 * sizeof(int));
                mapOne[numOne][0] = i;
                mapOne[numOne][1] = j;
                numOne++;
            } else {
                mapZero[numZero] = (int *)malloc(2 * sizeof(int));
                mapZero[numZero][0] = i;
                mapZero[numZero][1] = j;
                numZero++;
            }
        }
    }

    if (numOne == 0 || numOne == row * col) {
        return dis;
    }
    
    int oneStart = 0;
    int oneEnd = numOne;    
    for (int i = 0; i < numZero; i++){
        int xZero = mapZero[i][0];
        int yZero = mapZero[i][1]; 
        int distance = row + col - 2;
        int index = 1;
        int tmpJ = 0;
        for (int j = oneStart; j < oneEnd; j++) {
            int xOne = mapOne[j][0];
            int yOne = mapOne[j][1];
            
            int tmp = abs(xOne - xZero) + abs(yOne - yZero); 
            if (tmp < dis) { 
                index = 0;
                break;
            }

            if (tmp < distance) {                
                distance = tmp;
                tmpJ = j;
            }
            if (j + 1 < numOne) {
                int nextX = mapOne[j + 1][0];
                if ((nextX - xZero) > tmp)  {
                    break;
                }
            }        
        }       
        if (index == 1) {
            dis = (distance > dis) ? distance : dis;
            oneStart = (tmpJ >= *gridColSize + dis) ? tmpJ - *gridColSize - dis : oneStart;
        }        
    }
    return dis;
}
    
    
    

```

```
