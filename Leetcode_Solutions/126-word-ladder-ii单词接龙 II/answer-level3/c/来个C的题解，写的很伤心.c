```


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define INVALID_INDEX 0xffffffff
#define PRT_SW 0

typedef struct {
    unsigned int adjNum;
    unsigned int *adjIndex;
} WordAdj;

typedef struct {
    unsigned int isOk;
    unsigned int minLen;
    unsigned int nextNum;
    unsigned int *nextIndex;
} WordSearch;

typedef struct outPut {
    char **str;
    struct outPut *next;
} OutPutList;

WordAdj *g_wordAdjInfo = NULL;
WordSearch *g_wordSearchInfo = NULL;
OutPutList *g_outPutStr;
unsigned int g_outPutStrNum = 0;

#if (PRT_SW == 1)
#define DebugPrt printf
#else
#define DebugPrt
#endif

int CheckEndWord(char *endWord, char **wordList, int wordListSize, unsigned int *endWordIndex)
{
    unsigned i;
    for (i = 0; i < wordListSize; i++) {
        if (strcmp(endWord, wordList[i]) == 0) {
            *endWordIndex = i;
            return 0;
        }
    }
    return -1;
}

int CheckIsAdjWord(char *word1, char *word2)
{
    unsigned int i = 0;
    unsigned int diffNum = 0;
    unsigned int len = strlen(word1);
    while (i < len) {
        if (word1[i] != word2[i]) {
            diffNum++;
        }
        i++;
    }
    if (diffNum == 1) {
        return 0;
    }
    return -1;
}

void getOptNext(unsigned int *outMinNum, unsigned int *outMinNode, unsigned int totalWordNum)
{
    unsigned int i, min, outMinNumL = 0;
    WordSearch *wordSearchInfo = g_wordSearchInfo;
    min = INVALID_INDEX;
    *outMinNum = 0;
    for (i = 0; i < totalWordNum; i++) {
        if (wordSearchInfo[i].isOk == 1) {
            continue;
        }

        if (wordSearchInfo[i].minLen < min) {
            min = wordSearchInfo[i].minLen;
            outMinNode[outMinNumL++] = i;
        }
    }

    *outMinNum = outMinNumL;
}

void DfsSearch(char **newWordList, unsigned int endWordIndex, unsigned int *oneList, unsigned int oneListNum, unsigned int minLen)
{
    static int num = 0;
    unsigned int i, lastIndex, nextIndex;
    OutPutList *node;
    char **outStr;
    char *charstr;
    WordSearch *wordSearchInfo = g_wordSearchInfo;
    if (oneListNum > minLen) {
        return;
    }
    
    lastIndex = oneList[oneListNum - 1];
    if (lastIndex == endWordIndex) {
        outStr = (char **)malloc(sizeof(char *) * oneListNum);
        if (outStr == NULL) {
            return;
        }
        node = (OutPutList *)malloc(sizeof(OutPutList));
        if (node == NULL) {
            return;
        }

        for (i = 0; i < oneListNum; i++) {
            charstr = (char *)malloc(sizeof(char) * (strlen(newWordList[oneList[i]]) + 1));
            strcpy(charstr, newWordList[oneList[i]]);
            outStr[i] = charstr;
        }

        node->str = outStr;
        node->next = g_outPutStr->next;
        g_outPutStr->next = node;
        g_outPutStrNum++;
        return;
    }
    
    for (i = 0; i < wordSearchInfo[lastIndex].nextNum; i++) {
        nextIndex = wordSearchInfo[lastIndex].nextIndex[i];
        if ((wordSearchInfo[nextIndex].minLen == oneListNum + 1) && (oneListNum < minLen)) {
            oneList[oneListNum] = nextIndex;
            DfsSearch(newWordList, endWordIndex, oneList, oneListNum + 1, minLen);
        }
    }
}

int CalcResultByDfs(char **newWordList, unsigned int endWordIndex, unsigned int minLen)
{
    unsigned int *oneList, oneListNum = 0;
    WordSearch *wordSearchInfo = g_wordSearchInfo;

    oneList = (unsigned int *)malloc(sizeof(unsigned int) * minLen);
    if (oneList == NULL) {
        return -1;
    }

    oneListNum = 1;
    oneList[0] = 0;  // start
    DfsSearch(newWordList, endWordIndex, oneList, oneListNum, minLen);
    free(oneList);
    return 0;
}

int BfsSearch(char **newWordList, unsigned int totalWordNum, unsigned int endWordIndex, unsigned int *minLen)
{
    unsigned int i, j;
    unsigned int currPos, searchNum = 0;
    unsigned int adjIndex, currIndex;
    unsigned int findFlag = 0;
    unsigned int *searchList;
    WordAdj *wordAdjInfo = g_wordAdjInfo;
    WordSearch *wordSearchInfo = g_wordSearchInfo;

    searchList = (unsigned int *)malloc(sizeof(unsigned int) * totalWordNum);
    if (searchList == NULL) {
        return -1;
    }

    currPos = 0;
    searchNum = 1;
    searchList[0] = 0;
    wordSearchInfo[0].isOk = 1;
    wordSearchInfo[0].minLen = 1;

    while ((currPos < searchNum) && (currPos < totalWordNum)) {
        currIndex = searchList[currPos];
        for (i = 0; i < wordAdjInfo[currIndex].adjNum; i++) {
            adjIndex = wordAdjInfo[currIndex].adjIndex[i];
            wordSearchInfo[currIndex].nextIndex[wordSearchInfo[currIndex].nextNum++] = adjIndex;

            if (wordSearchInfo[adjIndex].isOk == 0) {
                wordSearchInfo[adjIndex].isOk = 1;
                wordSearchInfo[adjIndex].minLen = wordSearchInfo[currIndex].minLen + 1;
                searchList[searchNum++] = adjIndex;
            }
            if (adjIndex == endWordIndex) {
                findFlag = 1;
            }
        }
        currPos++;
    }

    free(searchList);
    if (findFlag == 1) {
        *minLen = wordSearchInfo[endWordIndex].minLen;
        return 0;
    }
    return -1;
}

int CreateWordAdj(char **newWordList, unsigned int totalWordNum)
{
    unsigned int i, j;

    // first is beginWord, other word index begin i+1
    for (i = 0; i < totalWordNum - 1; i++) {
        for (j = i + 1; j < totalWordNum; j++) {
            if (CheckIsAdjWord(newWordList[i], newWordList[j]) == 0) {
                g_wordAdjInfo[i].adjIndex[g_wordAdjInfo[i].adjNum++] = j;
                if (i == 0) {  // 不能反向找
                    continue;
                }

                g_wordAdjInfo[j].adjIndex[g_wordAdjInfo[j].adjNum++] = i;
            }
        }
    }

    return 0;
}

int MallocMem(char ***newWordList, unsigned int totalWordNum)
{
    unsigned int i;

    *newWordList = (char **)malloc(sizeof(char *) * (totalWordNum));
    if (*newWordList == NULL) {
        return -1;
    }

    g_wordAdjInfo = (WordAdj *)malloc(sizeof(WordAdj) * totalWordNum);
    if (g_wordAdjInfo == NULL) {
        return -1;
    }

    g_wordSearchInfo = (WordSearch *)malloc(sizeof(WordSearch) * totalWordNum);
    if (g_wordSearchInfo == NULL) {
        return -1;
    }

    g_outPutStr = (OutPutList *)malloc(sizeof(OutPutList));
    if (g_outPutStr == NULL) {
        return -1;
    }
    g_outPutStr->next = NULL;

    for (i = 0; i < totalWordNum; i++) {
        g_wordAdjInfo[i].adjNum = 0;
        g_wordAdjInfo[i].adjIndex = (unsigned int *)malloc(sizeof(unsigned int) * totalWordNum);
        if (g_wordAdjInfo[i].adjIndex == NULL) {
            return -1;
        }
        g_wordSearchInfo[i].isOk = 0;
        g_wordSearchInfo[i].minLen = INVALID_INDEX;
        g_wordSearchInfo[i].nextNum = 0;
        g_wordSearchInfo[i].nextIndex = (unsigned int *)malloc(sizeof(unsigned int) * totalWordNum);
        if (g_wordSearchInfo[i].nextIndex == NULL) {
            return -1;
        }
    }

    return 0;
}

void FreeMem(char **newWordList, unsigned int totalWordNum)
{
    unsigned int i;
    OutPutList *pTmp, *pRel;
    for (i = 0; i < totalWordNum; i++) {
        if (g_wordAdjInfo[i].adjIndex != NULL) {
            free(g_wordAdjInfo[i].adjIndex);
        }
        if (g_wordSearchInfo[i].nextIndex != NULL) {
            free(g_wordSearchInfo[i].nextIndex);
        }
    }

    if (newWordList != NULL) {
        free(newWordList);
    }
    if (g_wordAdjInfo != NULL) {
        free(g_wordAdjInfo);
    }
    if (g_wordSearchInfo != NULL) {
        free(g_wordSearchInfo);
    }
    if (g_outPutStr != NULL) {
        free(g_outPutStr);
    }

    pTmp = g_outPutStr;
    while ((pTmp != NULL) && (i < g_outPutStrNum + 1)) {  // 包含头结点
        pRel = pTmp;
        pTmp = pTmp->next;
        free(pRel);
        i++;
    }
}

char *** findLadders(char *beginWord, char *endWord, char **wordList, int wordListSize, int* returnSize, int** returnColumnSizes){
    unsigned i;
    int mallocColumnSizes = 0;
    char **newWordList = NULL;
    unsigned int totalWordNum = wordListSize + 1;
    unsigned int endWordIndex = 0;
    char ***outPutAll = NULL;   // 不释放
    OutPutList *pTmp;

    *returnSize = 0;
    g_outPutStrNum = 0;
    if (MallocMem(&newWordList, totalWordNum) != 0) {
        FreeMem(newWordList, totalWordNum);
        return NULL;
    }

    newWordList[0] = beginWord;
    int num = 1;
    for (i = 0; i < wordListSize; i++) {
        if (strcmp(wordList[i], beginWord) != 0) {
            newWordList[num++] = wordList[i];
            
        }
    }
    totalWordNum = num;

    if (CheckEndWord(endWord, newWordList, totalWordNum, &endWordIndex) != 0) {
        FreeMem(newWordList, totalWordNum);
        return NULL;
    }

    if (CreateWordAdj(newWordList, totalWordNum) != 0) {
        FreeMem(newWordList, totalWordNum);
        return NULL;
    }

    if (BfsSearch(newWordList, totalWordNum, endWordIndex, &mallocColumnSizes) != 0) {
        FreeMem(newWordList, totalWordNum);
        return NULL;
    }

    if (CalcResultByDfs(newWordList, endWordIndex, mallocColumnSizes) != 0) {
        FreeMem(newWordList, totalWordNum);
        return NULL;
    }

    unsigned int lenl= sizeof(char**) * g_outPutStrNum;
    outPutAll = (char ***)malloc(lenl);  // 不释放
    if (outPutAll == NULL) {
        FreeMem(newWordList, totalWordNum);
        return NULL;
    }

    i = 0;
    pTmp = g_outPutStr->next;
    while ((pTmp != NULL) && (i < g_outPutStrNum)) {
        outPutAll[i] = pTmp->str;
        pTmp= pTmp->next;
        i++;
        
    }
    
    for (i = 0; i < g_outPutStrNum; i++) {
        DebugPrt("[%d]:", i);
        for (int j = 0; j < mallocColumnSizes; j++) {
          DebugPrt(" %s", outPutAll[i][j]);
        }
        DebugPrt("\n");
    }
    
    *returnSize = g_outPutStrNum;
    *returnColumnSizes = (int *)malloc(sizeof(int) * g_outPutStrNum);
    if (*returnColumnSizes == NULL) {
        FreeMem(newWordList, totalWordNum);
        return NULL;
    }
    
    for (i = 0; i < g_outPutStrNum; i++) {
        (*returnColumnSizes)[i] = mallocColumnSizes;
    }
    
    FreeMem(newWordList, totalWordNum);

    return outPutAll;
}



```
