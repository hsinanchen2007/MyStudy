### 解题思路
此处撰写解题思路

### 代码

```c
int leastBricks(int** wall, int wallSize, int* wallColSize){
    short cnt[60000] = {0};
    int i, j, tmp;

    for (i = 0; i < wallSize; i++){
        tmp = 0;
        for (j = 0; j < (wallColSize[i] - 1); j++){
            tmp += wall[i][j];
            cnt[tmp]++;
        }
    }

    tmp = 0;
    for (i = 0; i < 10000; i++){
        if (cnt[i] > tmp){
            tmp = cnt[i];
        }
    }

    return wallSize - tmp;
}
```