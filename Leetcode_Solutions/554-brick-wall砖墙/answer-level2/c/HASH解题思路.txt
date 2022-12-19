### 解题思路
主要是能想到HASH的组织结构；
1.遍历每行转头，把遇到的转头总和相加作为KEY，如果其他行有相同的key则说明可以不穿过转头。
2.遍历完成后，取HASH表中可以穿过的最大值，墙的高度减去这个值就是串转头的最小值。

### 代码

```c
typedef struct My_hash_node{
    int sum;
    int count;
    UT_hash_handle hh;
}MY_HASH_NODE_S;

MY_HASH_NODE_S * g_node = NULL;

int leastBricks(int** wall, int wallSize, int* wallColSize){
    int minVal = wallSize;
    int maxWide = 0;
    int maxBlock = 0;
    int tmpVal = 0;
    int tmpRet = 0;
    MY_HASH_NODE_S *cur = NULL;
    MY_HASH_NODE_S *tmp = NULL;
   
    if (wallSize == 1 && wallColSize[0] == 1){
        return 1;
    }

    for(int i = 0; i < wallSize; i++) {
        tmpVal = 0;
        for(int j = 0; j < wallColSize[i]-1; j++){
            tmpVal += wall[i][j];
            HASH_FIND_INT(g_node, &tmpVal, cur);
            if(cur == NULL) {
                cur = (MY_HASH_NODE_S *)malloc(sizeof(MY_HASH_NODE_S));
                cur->sum = tmpVal;
                cur->count = 1;
                HASH_ADD_INT(g_node, sum, cur);
            } else {
                cur->count++;
            }
        }
    }
    HASH_ITER(hh, g_node, cur, tmp){
        minVal = minVal < (wallSize - cur->count) ? minVal : (wallSize - cur->count);
        HASH_DEL(g_node,cur);
        free(cur);
        cur = NULL;
    }
    return minVal;
    /*
    for (int i = 1; i < maxBlock; i++) {
        for(int j = 0; j < wallSize; j++) {
            tmpVal = i;
            for(int n = 0; n < wallColSize[j]; n++) {
                if (wall[j][n] < tmpVal) {
                    tmpVal = tmpVal - wall[j][n];
                } else if (wall[j][n] > tmpVal) {                   
                    tmpRet++;
                   // printf("i:%d j:%d, n:%d tmp:%d, wal %d tmp %d\n",i, j, n,tmpRet,wall[j][n],tmpVal);
                    break;
                }else {
                    break;
                }
            }
        }
        minVal = minVal < tmpRet ? minVal : tmpRet;
        tmpRet = 0;
    }
    
    return minVal;
    */
}
```