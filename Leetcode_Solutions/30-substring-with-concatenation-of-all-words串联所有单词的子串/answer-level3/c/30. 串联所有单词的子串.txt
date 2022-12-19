### 解题思路
外层循环控制起始位置，内存循环按单词查找，找到把单词对应的数组flagArr对应位置置TRUE，
当s遍历完，或者遇到第一个无法在words里找到的单词，退出内层循环，判断flagArr是否全部为TRUE，
全部为TRUE说明匹配成功，保存当前索引，置空flagArr，进入下一次循环，一直循环到needFinds位置。
![image.png](https://pic.leetcode-cn.com/33225af66bb1a7e7c248c56147e149b81e4ddb27f5797370e1cb7f77954fb1fe-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int LastFindFlag(int* flagArr, int wordsSize);
int Find(char* compareStr, int* flagArr, char **words, int wordsSize);
#define FALSE -1
#define TRUE 1

int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    *returnSize = 0;
    if (s == NULL || strlen(s) == 0 || words == NULL || wordsSize == 0) {
        return NULL;
    }
    int sLen = strlen(s);
    int wLen = strlen(words[0]);
    int* ret = (int *)malloc(sizeof(int) * sLen);    
    memset(ret, 0, sizeof(int) * sLen);
    int* flagArr = (int*)calloc(sizeof(int), wordsSize);
    char* compareStr = (char*)calloc(sizeof(char), wLen + 1);
    int needFinds = sLen - wLen * wordsSize;
    int retFindflag = FALSE;
    for (int i = 0; i <= needFinds; i++) {
        retFindflag = FALSE;
        for (int j = i; j <= sLen - wLen; j += wLen) {
            strncpy(compareStr, s + j, wLen);    
            retFindflag = Find(compareStr, flagArr, words, wordsSize);
            if (retFindflag == FALSE) {
                break;
            }
        }
        if (LastFindFlag(flagArr, wordsSize) == TRUE) {
            ret[*returnSize] = i;
            *returnSize += 1;
        }
        memset(flagArr, 0, sizeof(int) * wordsSize);
    }
    free(flagArr);
    free(compareStr);
    return ret;
}

int Find(char* compareStr, int* flagArr, char **words, int wordsSize)
{
    for (int i = 0; i < wordsSize; i++) {
        if (flagArr[i] == TRUE) {
            continue;
        }     
        if (strcmp(compareStr, words[i]) == 0) {
            flagArr[i] = TRUE;
            return TRUE;
        }
    }
    return FALSE;
}

int LastFindFlag(int* flagArr, int wordsSize) {
     for (int i = 0; i < wordsSize; i++) {
         if (flagArr[i] != TRUE) {
             return FALSE;
         }
     }
     return TRUE;
}
```