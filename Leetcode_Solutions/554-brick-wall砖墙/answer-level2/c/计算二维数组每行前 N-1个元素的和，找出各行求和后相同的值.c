参考了作者：steamedfish-2 的解法

#define WALLMAXCOLSIZE 20001
int cmp(const void *p1, const void *p2) 
{
    int *a = (int *)p1;
    int *b = (int *)p2;
    return (*b - *a); // 降序排
}

int leastBricks(int** wall, int wallSize, int* wallColSize){
    if (wall == NULL || wallSize == 0 || *wallColSize == 0) {
        return  0;
    }

    int result[WALLMAXCOLSIZE] = {0};
    memset(result, 0, sizeof(int) * WALLMAXCOLSIZE);

    int col;
    int row;
    int sum = 0;
    int idx = 0;
    for (row = 0; row < wallSize; row++) {
        sum = wall[row][0]; // 计算每行元素，每个元素前面元素的和
        for (col = 0; col < wallColSize[row] - 1; col++) { // 每行元素计算的次数为 行元素总个数 - 1
            if (col == 0) {
                result[idx] = sum;
            } else {
                sum += wall[row][col];
                result[idx] = sum;
            } 
            idx++;   
        }
    }

    qsort(result, idx, sizeof(int), cmp); 

    int i;
    int max = 1;
    int cnt = 1;
    printf("idx = %d\n", idx);
    
    for (i = 0; i < idx - 1; i++) {
        printf("result[%d]: ", i);
        printf(" %d", result[i]);
        if ((result[i] == result[i+1]) && result[i] != 0) {
            cnt++;
            if (cnt > max) {
                max = cnt;
            }
        } else {
            cnt = 1;
        }
    }
        printf(" i = %d, result[i] = %d ", i, result[i]);
        printf("max cnt: %d\n", max);

    //计算数组最多有几列
    qsort(wallColSize, wallSize, sizeof(int),  cmp);
    int maxCol = wallColSize[0];

    if (maxCol == 1) {
        return wallSize;
    }

    return wallSize - max;

}