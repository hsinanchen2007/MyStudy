### 解题思路
先看下有没有坏橘子，如果没有，那么只有两种情况，0 or -1
如果有，统计好橘子总数good；
标记每分钟变坏的橘子的位置，并记录变坏总个数changebad；
直到good-changebad == 0时即为所需时间；返回
如果changebad为0，但是good > 0；
那么剩余的good永远不会变质。返回-1



### 代码

```c
int flushArray(int** grid, int gridSize, int* gridColSize){
    int count = 0;
    int i, j;

    for(i = 0; i < gridSize; i++){
        for(j = 0; j < gridColSize[0]; j++){
            if(grid[i][j] == 1){
                if((i-1 >= 0 && grid[i-1][j] == 2)||\
                (j-1 >= 0 && grid[i][j-1] == 2)||\
                (j+1 < gridColSize[0] && grid[i][j+1] == 2)||\
                (i+1 < gridSize && grid[i+1][j] == 2)){
                    grid[i][j] = 3;
                    count++;
                }
            }
        }
    }

    for(i = 0; i < gridSize; i++){
         for(j = 0; j < gridColSize[0]; j++){
             if(grid[i][j] == 3){
                grid[i][j] = 2;
             }
        }
    }

    return count;

}


int orangesRotting(int** grid, int gridSize, int* gridColSize){

    int i, j;
    int flag = 0;
    int count = 0;
    int time = 0;

    for(i = 0; i < gridSize; i++){
         for(j = 0; j < gridColSize[0]; j++){
             if(grid[i][j] == 2){
                flag++;
             }
             else if(grid[i][j] == 1){
                count++;
             }
        }
    }

    if(flag == 0){
        if(count == 0){
            return 0;
        }
        else{
            return -1;
        }
    }
        

    
    while(count > 0){
        i = 0;
        i = flushArray(grid, gridSize, gridColSize);
        count -= i;
        if(i == 0 && count > 0){
            return -1;
        }
        time++;
    }

    return time;

}
```