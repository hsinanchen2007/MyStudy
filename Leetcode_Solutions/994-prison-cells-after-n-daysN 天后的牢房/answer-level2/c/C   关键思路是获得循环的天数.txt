/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//参考了作者：alanout的实现

 void fun(int* cells, int cellsSize, int N, int* retArr)
 {
    int ret;
    int daycycle = 0;
    int *dayresult = (int *)malloc(sizeof(int) * cellsSize);
    memset(dayresult, 0, sizeof(int) * cellsSize);

    int *firstDay = (int *)malloc(sizeof(int) * cellsSize);
    memset(firstDay, 0, sizeof(int) * cellsSize);

    int *temp = (int *)malloc(sizeof(int) * cellsSize);
    memcpy(temp, cells, sizeof(int) * cellsSize);
   
   //计算出第一天后cells的状态，再以后，以这个状态为参考找循环的天数
    int i;
    for (i = 1; i < cellsSize - 1; i++) {
            firstDay[i] = (temp[i - 1] == temp[i + 1]) ? 1 : 0;
    }
    firstDay[0] = 0;
    firstDay[cellsSize - 1] = 0;

    memcpy(temp, firstDay, sizeof(int) * cellsSize);
     while (true) {
        daycycle++;
        for (i = 1; i < cellsSize - 1; i++) {
            dayresult[i] = (temp[i - 1] == temp[i + 1]) ? 1 : 0;
        }

        ret = memcmp(dayresult, firstDay, sizeof(int) * cellsSize);
        if (ret == 0) {
            break;
        }
        memcpy(temp, dayresult, sizeof(int) * cellsSize);
     }

    int remainDays = (N - 1) % daycycle;

    memcpy(retArr, firstDay, sizeof(int) * cellsSize);
    int idx;
    for (idx = 0; idx < remainDays; idx++) {
        for (i = 1; i < cellsSize - 1; i++) {
            dayresult[i] = (retArr[i - 1] == retArr[i + 1]) ? 1 : 0;
        }    
        memcpy(retArr, dayresult, sizeof(int) * cellsSize);
    }

 }


int* prisonAfterNDays(int* cells, int cellsSize, int N, int* returnSize){
    if (cells == NULL || cellsSize == 0 || (N < 1 || N > 1000000000)) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = cellsSize;
    int *retArr = (int *)malloc(sizeof(int) * cellsSize);
    if (retArr == NULL) {
        return NULL;
    }

    memset(retArr, 0, sizeof(int) * cellsSize);
    fun(cells, cellsSize, N, retArr);
    return retArr;

}