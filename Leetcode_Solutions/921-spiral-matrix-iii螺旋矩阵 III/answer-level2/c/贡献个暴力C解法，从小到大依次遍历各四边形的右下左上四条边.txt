int** spiralMatrixIII(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes){
    int nums = R*C;
    int ** re = (int **)malloc(sizeof(int *)*nums);
    int ** map = (int **)malloc(sizeof(int *)*R);
    for (int i = 0; i < R; i++){
        map[i] = malloc(sizeof(int)*C);
        for (int j = 0; j < C; j++){
            map[i][j] = 0;
        }
    }
    * returnSize = nums;
    int * retCol = (int *)malloc(sizeof(int)*nums);
    for (int k = 0; k < nums; k++){
        retCol[k] = 2;
    }
    * returnColumnSizes = retCol;
    int head = 0;
    int rear = 1;
    int next[2];
    re[0] = (int *)malloc(sizeof(int)*2);
    re[0][0] = r0;
    re[0][1] = c0;
    map[r0][c0] = 1;
    int dis = 0;
    nums--;
    while (nums > 0){
        dis++;
        printf("dis: %d nums: %d\n",dis,nums);
        for (int i = re[head][0] - dis + 1; i <= re[head][0] + dis; i++){
            next[0] = i;
            next[1] = re[head][1] + dis;
            if (next[0] >= 0 && next[0] < R && next[1] >= 0 && next[1] < C && map[next[0]][next[1]] == 0){
                printf("%d,%d\n",next[0],next[1]);
                re[rear] = (int *)malloc(sizeof(int)*2);
                re[rear][0] = next[0];
                re[rear][1] = next[1];
                map[next[0]][next[1]] = 1;
                rear++;
                nums--;
            }
        }
        for (int i = re[head][1] + dis; i >= re[head][1] - dis; i--){
            next[0] = re[head][0] + dis;
            next[1] = i;
            if (next[0] >= 0 && next[0] < R && next[1] >= 0 && next[1] < C && map[next[0]][next[1]] == 0){
                printf("%d,%d\n",next[0],next[1]);
                re[rear] = (int *)malloc(sizeof(int)*2);
                re[rear][0] = next[0];
                re[rear][1] = next[1];
                map[next[0]][next[1]] = 1;
                rear++;
                nums--;
            }
        }
        for (int i = re[head][0] + dis; i >= re[head][0] - dis; i--){
            next[0] = i;
            next[1] = re[head][1] - dis;
            if (next[0] >= 0 && next[0] < R && next[1] >= 0 && next[1] < C && map[next[0]][next[1]] == 0){
                printf("%d,%d\n",next[0],next[1]);
                re[rear] = (int *)malloc(sizeof(int)*2);
                re[rear][0] = next[0];
                re[rear][1] = next[1];
                map[next[0]][next[1]] = 1;
                rear++;
                nums--;
            }
        }
        for (int i = re[head][1] - dis; i <= re[head][1] + dis + 1; i++){
            next[0] = re[head][0] - dis;
            next[1] = i;
            if (next[0] >= 0 && next[0] < R && next[1] >= 0 && next[1] < C && map[next[0]][next[1]] == 0){
                printf("%d,%d\n",next[0],next[1]);
                re[rear] = (int *)malloc(sizeof(int)*2);
                re[rear][0] = next[0];
                re[rear][1] = next[1];
                map[next[0]][next[1]] = 1;
                rear++;
                nums--;
            }
        }
    }    
    return re;
}