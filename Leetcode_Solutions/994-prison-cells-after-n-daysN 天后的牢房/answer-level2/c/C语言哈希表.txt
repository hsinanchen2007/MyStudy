### 解题思路
使用编解码思想完成状态更新
在状态变化中查找变化规律，使用哈希表记录状态

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define EMPTY 0
 #define FULL 1
 #define EMPTY2FULL 2 // 0->2
 #define FULL2EMPTY 3 // 1->3
 #define CELLSIZE 8
 #define MAXSTATUS 127
 #define INVALID (-1)
 #define PRINTF // printf

int UpdateStatus(int* pRet, int cellsSize)
{
    int iRet = -1;
    for(int j = 1; j < (cellsSize - 1); j++){
        if((pRet[j - 1] + pRet[j + 1]) % 2 == 0){
            if(pRet[j] == EMPTY) {
                pRet[j] = EMPTY2FULL;
            }
        } else {
            if(pRet[j] == FULL) {
                pRet[j] = FULL2EMPTY;
            }
        }
    }
    for(int j = 1; j < (cellsSize - 1); j++){
        if(pRet[j] > FULL) {
            pRet[j] = ((pRet[j] - 1) % 2);
        }
    }
    pRet[0] = 0;
    pRet[cellsSize - 1] = 0;
    iRet &= 0;
    for(int j = 0; j < cellsSize; j++){
        iRet |= (pRet[j] << j);
    }
    return iRet;
}
int RepeatCheck(int N, int *pRet, int cellsSize, int *pStatus, int *pPos, int *curPos)
{
    int repeat = 0;
    for (int i = 0; i < MAXSTATUS; i++) {
        pStatus[i] = INVALID;
    }
    for(int i = 0; i < N; i++) { // N Days
        int iRet = UpdateStatus(pRet, cellsSize);
        if (pStatus[iRet] != INVALID) { // Repeated
            repeat = 1;
            break;
        }
        pStatus[iRet] = iRet;
        pPos[(*curPos)] = iRet;
        (*curPos)++;
    }
    return repeat;
}
int* prisonAfterNDays(int* cells, int cellsSize, int N, int* returnSize){
    *returnSize = 0;
    int *pRet = (int *)malloc(cellsSize * sizeof(int));
    if (pRet == NULL) {
        goto END;
    }
    memcpy(pRet, cells, (cellsSize * sizeof(int)));
    if(cellsSize != CELLSIZE) {
        goto END;
    }
    int hashStatus[MAXSTATUS] = {0};
    int hashPos[MAXSTATUS] = {0};
    int curPos = 0;
    *returnSize = cellsSize;
    int repeat = RepeatCheck(N, pRet, cellsSize, &hashStatus, &hashPos, &curPos);
    if(repeat == 0){
        goto END;
    }
    for(int j = 0; j < cellsSize; j++){
        if((((hashPos[(N - 1) % curPos]) >> j) & 1)) {
            pRet[j] = 1;
            continue;
        }
        pRet[j] = 0;
    }
END:
    return pRet;
}
```