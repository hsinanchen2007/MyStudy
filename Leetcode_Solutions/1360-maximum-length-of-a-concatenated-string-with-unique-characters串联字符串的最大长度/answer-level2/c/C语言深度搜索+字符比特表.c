### 解题思路
深度搜索+字符比特表
字符重复性用字符比特表表示，即按照字符偏移置上对应的比特，按照比特的置位情况判断是否有效
深度搜索

### 代码

```c
typedef struct stBitMap{
    int bitMap;
    int len;
}STBITMAP;
#define MAX(a, b) (((a) > (b)) ? (a): (b))
#define PRINTF // printf
int g_maxLen = 0;
STBITMAP* InitInput(char ** arr, int arrSize)
{
    STBITMAP *pInput = (STBITMAP *)malloc(arrSize * sizeof(STBITMAP));
    if (pInput == NULL) {
        goto END;
    }
    for (int i = 0; i < arrSize; i++) {
        int bitsMap = 0;
        int len = strlen(&arr[i][0]);
        for (int j = 0; j < len; j++) {
            int CurBit = (1 << (arr[i][j] - 'a'));
            if((bitsMap & CurBit) == CurBit){
                bitsMap = 0;
                len = 0; // 单个出现重复,开始没想到怎么处理比较合适
                PRINTF("Repeat\n");
                break;
            }
            bitsMap |= CurBit;
        }
        pInput[i].bitMap = bitsMap;
        pInput[i].len = len;
    }
END:
    return pInput;
}

void DfsSearch(STBITMAP *pInput, int size, int curIndex, int *pCurbitMap, int *pCurLen)
{
    for(int i = curIndex; i < size; i++) { // 数组序号组成的隐式邻接矩阵
        if(((*pCurbitMap) & (pInput[i].bitMap)) != 0){
            PRINTF("Matched%d %x %x %x\n", i, pInput[i].bitMap, (*pCurbitMap), ((*pCurbitMap) & (pInput[i].bitMap)));
            continue;  // 有重复字符，跳过当前的，即不取当前的
        }
        (*pCurbitMap) |= pInput[i].bitMap; // 位置信息
        (*pCurLen) += pInput[i].len;
        g_maxLen = MAX(g_maxLen, (*pCurLen));
        PRINTF("%d %x %x\n", i, pInput[i].bitMap, (*pCurbitMap));
        DfsSearch(pInput, size, (i + 1), pCurbitMap, pCurLen);
       
        (*pCurbitMap) ^= pInput[i].bitMap;
        (*pCurLen) -= pInput[i].len;  // 回溯，还原后查找右边的
    }
}

int maxLength(char ** arr, int arrSize){
    g_maxLen = 0;
    int* pInput = InitInput(arr, arrSize);
    if (pInput == NULL) {
        goto END;
    }
    int curBitMap = 0;
    int curLen = 0;
    DfsSearch(pInput, arrSize, 0,  &curBitMap, &curLen);
END:
    return g_maxLen;
}
```