思想主要是使用BFS按层进行寻找，就是首先找距离为1的一圈，再找为2的一圈，只要在某一圈找到一个1，立即返回距离，这样可以避免很多冗余的查找。


```
/*
first,find a zero
then, BFS
if the distance reaches 2N, stop.
*/
int BFS(int **grid, int gridSize, int rowIndex, int colIndex);
bool judge(int rowIndex, int colIndex, int gridSize);

int maxDistance(int** grid, int gridSize, int* gridColSize){
    int max_distance = -1;
    int zeroNum = 0;
    for(int i=0; i< gridSize; i++){
        for(int j=0; j< gridSize; j++){
            if (grid[i][j] == 0){  
                zeroNum ++;
            }
        }
    }
    if (zeroNum == gridSize * gridSize){
        return -1;
    }
    int colIndex = 0;
    int rowIndex = 0;
    for(; rowIndex < gridSize; rowIndex++){
        colIndex = 0;
        for(; colIndex < gridSize; colIndex++){
            //printf("(%d, %d)\n", rowIndex, colIndex);
            if (grid[rowIndex][colIndex] == 1){  
                continue;
            }
            else{
                // find 0;
                int tmpDistance = BFS(grid, gridSize, rowIndex, colIndex);
                if (tmpDistance == -1){
                    return -1;
                }
                //printf("%d\n", tmpDistance);
                //printf("%d\n%d\n", rowIndex, colIndex);
                max_distance = tmpDistance > max_distance?tmpDistance:max_distance; 
            }
        }
    }
    return max_distance;
}


int BFS(int **grid, int gridSize, int rowIndex, int colIndex){
    int max_distance = -1;
    int spreadFlag = 1;
    int spreadTimes = 0;
    int tmpRowIndexAdd = 0;
    int tmpRowIndexDelete = 0;
    int tmpColIndexAdd = 0;
    int tmpColIndexDelete = 0;
    int BFSEnd = 0;
    int actualFind = 0;
    //printf("(%d, %d)%s\n", rowIndex, colIndex, "寻找中");
    while(spreadFlag){
        BFSEnd = 0;
        spreadTimes ++;
        //printf("%s%d%s\n", "第", spreadTimes, "波");
        for(int operations = 0; operations <= spreadTimes; operations++){
            actualFind += 4;
            tmpColIndexAdd = colIndex + operations;
            tmpColIndexDelete = colIndex - operations;
            tmpRowIndexAdd = rowIndex + spreadTimes - operations;
            tmpRowIndexDelete = rowIndex - spreadTimes + operations;
            if(judge(tmpRowIndexAdd, tmpColIndexAdd, gridSize)){
                //printf("(%d,%d):%d\n", tmpRowIndexAdd, tmpColIndexAdd, grid[tmpRowIndexAdd][tmpColIndexAdd]);
                if(grid[tmpRowIndexAdd][tmpColIndexAdd] == 1){
                    //printf("%d\n%d\n", tmpColIndexAdd, tmpRowIndexAdd);
                    max_distance = spreadTimes;
                    return max_distance;
                }
            }
            else{
                BFSEnd ++;
            }
            if(judge(tmpRowIndexAdd, tmpColIndexDelete, gridSize)){
                //printf("(%d,%d):%d\n", tmpRowIndexAdd, tmpColIndexDelete, grid[tmpRowIndexAdd][tmpColIndexDelete]);
                if(grid[tmpRowIndexAdd][tmpColIndexDelete] == 1){
                    max_distance = spreadTimes;
                    return max_distance;
                }
            }
            else{
                BFSEnd ++;
            }
            if(judge(tmpRowIndexDelete, tmpColIndexAdd, gridSize)){
                //printf("(%d,%d):%d\n", tmpRowIndexDelete, tmpColIndexAdd, grid[tmpRowIndexDelete][tmpColIndexAdd]);
                if(grid[tmpRowIndexDelete][tmpColIndexAdd] == 1){
                    max_distance = spreadTimes;
                    return max_distance;
                }
            }
            else{
                BFSEnd ++;
            }
            if(judge(tmpRowIndexDelete, tmpColIndexDelete, gridSize)){
                //printf("(%d,%d):%d\n", tmpRowIndexDelete, tmpColIndexDelete, grid[tmpRowIndexDelete][tmpColIndexDelete]);
                if(grid[tmpRowIndexDelete][tmpColIndexDelete] == 1){
                    max_distance = spreadTimes;
                    return max_distance;
                }
            }
            else{
                BFSEnd ++;
            }
        }
        if(BFSEnd == actualFind){
            //printf("%d\n", BFSEnd);
            spreadFlag = 0;
        }
    }
    return max_distance;
}


bool judge(int rowIndex, int colIndex, int gridSize){
    if ((rowIndex < gridSize) && (rowIndex > -1) && (colIndex < gridSize) && (colIndex > -1)){
        return true;
    }
    return false;
}
```



