### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int findInWords(char* str, char** words, int wordsSize)
{
    int wordLen = strlen(words[0]);
    int sLen = strlen(str);
    int *tmpArr = NULL;
    int ret = 0;
    
    tmpArr = (int*)malloc(sizeof(int) * wordsSize);
    memset(tmpArr, 0, sizeof(int) * wordsSize);

    for (int i = 0; i <= (wordsSize - 1) * wordLen; i += wordLen) {
        for (int j = 0; j < wordsSize; j++) {
            if(tmpArr[j] == 0) {
                int k = 0;
                while (k < wordLen) {
                    if(str[i + k] != words[j][k]) {
                        break;
                    }
                    k++;
                }
                if (k == wordLen) {
                    //printf("findwords %s index %d i %d\r\n",words[j], j, i);
                    tmpArr[j] = 1;
                    ret++;
                    break;
                }
            }
        }
    }
    /*
    for(int i = 0; i < wordsSize; i++) {
        if(tmpArr[i] == 0){
            ret = 0;
        }
    }
    */
    free(tmpArr);
    return ret == wordsSize ? 1:0;
}

int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize)
{
    int wordLen = 0;
    int sLen = 0;
    int *retArr = NULL;
    char *tmpArr = NULL;
    int find = 0;

    if (s == NULL || words == NULL || !wordsSize) {
        *returnSize = 0;
        return NULL;
    }
    sLen = strlen(s);
    wordLen = strlen(words[0]);
    if (sLen < wordLen * wordsSize || sLen == 0) {
        *returnSize = 0;
        return NULL;
    }

    retArr = (int*)malloc(sizeof(int) * sLen);
    memset(retArr, 0, sizeof(int) * sLen);
    *returnSize = 0;

    for (int i = 0; i < sLen -(wordsSize * wordLen) + 1; i++) {
       //printf("search %d\r\n",i);
       find = findInWords(s+i, words, wordsSize);// 匹配两个字符串
       //printf("find %d\r\n",find);
       if (find) {
           retArr[*returnSize] = i;
           (*returnSize)++;
       }
    }
    return retArr;
}
```