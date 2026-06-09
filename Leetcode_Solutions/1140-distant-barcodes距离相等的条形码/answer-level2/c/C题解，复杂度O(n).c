// 第一次做时，对条形码使用了qsort排序，后来发现连排序都不需要，只要找到出现次数最多的条形码，排在index 0,2,4...，剩下的先排剩下的偶数会，再排奇数会，不会出现相邻的相等这种情况，时间复杂度从O(nlogn)降到了O(n)。

typedef struct {
    int code;
    int cnt;
} CodeCnt;

CodeCnt codeCnt[10001];

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize){
    int i;
    
    memset(codeCnt, 0, sizeof(codeCnt));
    for (i = 1; i < 10001; i++) {
        codeCnt[i].code = i;
    }
    
    int *ret = malloc(sizeof(int) * barcodesSize);
   
    *returnSize = barcodesSize;   
    
    for (i = 0; i < barcodesSize; i++) {
        codeCnt[barcodes[i]].cnt++;
    }
    
    CodeCnt max = {1, codeCnt[1].cnt};
    for (i = 2; i < 10001; i++) {
        if (codeCnt[i].cnt > max.cnt) {
            max.cnt = codeCnt[i].cnt;
            max.code = codeCnt[i].code;
        }
    }
    int code = codeCnt[max.code].code;
    codeCnt[code].code = codeCnt[1].code;
    codeCnt[code].cnt = codeCnt[1].cnt;
    codeCnt[1].code = max.code;
    codeCnt[1].cnt = max.cnt;
    
    int readIdx = 1;
    int readCnt = 0;
    int writeIdx = 0;
    
    while (writeIdx < barcodesSize) {
        if (codeCnt[readIdx].cnt <= readCnt) {
            readCnt = 0;
            readIdx++;
            continue;
        }
        
        ret[writeIdx] = codeCnt[readIdx].code;
        writeIdx += 2;
        readCnt++;
    }

    writeIdx = 1;
    while (writeIdx < barcodesSize) {
        if (codeCnt[readIdx].cnt <= readCnt) {
            readCnt = 0;
            readIdx++;
            continue;
        }
        
        ret[writeIdx] = codeCnt[readIdx].code;
        writeIdx += 2;
        readCnt++;
    }

    return ret;
}

