```
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int orange[1000][2];
    int direction[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int head = 0;
    int rear = 0;
    int rearTmp = 0;
    int numGood = 0;
    int time = 0;
    int next[2];
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridColSize[0]; j++){
            if (grid[i][j] == 2){
                orange[rear][0] = i;
                orange[rear][1] = j;
                rear++;
            } else if (grid[i][j] == 1){
                numGood++;
            }
        }
    }
    if (numGood == 0){
        return 0;
    }
    rearTmp = rear;
    while (head < rear){
        if (head == rearTmp){
            time++;
            rearTmp = rear;
        }
        for (int i = 0; i < 4; i++){
            next[0] = orange[head][0] + direction[i][0];
            next[1] = orange[head][1] + direction[i][1];
            if (next[0] >= 0 && next[0] < gridSize && next[1] >= 0 && next[1] < gridColSize[0] && grid[next[0]][next[1]] == 1){
                grid[next[0]][next[1]] = 2;
                orange[rear][0] = next[0];
                orange[rear][1] = next[1];
                rear++;
                numGood--;
            }
        }
        head++;
    }
    if (numGood > 0){
        return -1;
    }
    return time;
}
```
