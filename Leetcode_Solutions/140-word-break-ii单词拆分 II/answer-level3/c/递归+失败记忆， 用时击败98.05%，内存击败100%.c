### 解题思路
不记忆，对于大量数据来说，肯定会超时。
这里用failArr记录了失败点。假设当前点为n，为失败点，即后续添加任何字符串都不能匹配。那么对于前边的某个点来说，假设为m点，如果m加上某个长度为失败n点，或者加上数组其他字符串也是不匹配的，那么这个m点也是失败点。这样将n前边的失败点推出来。对于失败点，直接返回。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_LEN  1024
char **ret;
int index1;
char failArr[MAX_LEN];

bool isSame(char *s, char *p, int len) {
    int i;

    for (i = 0; i < len; i++) {
        if (s[i] != p[i]) {
            return false;
        }
    }

    return true;
}

void isSub(char *src, char *s, char** wordDict, int wordDictSize, int *tmp, int tmpIndex) {
    int len;
    int i, j;
    int falseTimes = 0;
    int index = 0;
    int index2 = 0;
    char *str = NULL;
    int fail = 0;

    if (*s == '\0') {
        str = (char*)malloc(sizeof(char) * MAX_LEN);
        for (i = 0; i < tmpIndex; i++) {
            for (j = 0; j < tmp[i]; j++) {
                str[index++] = src[index2++];
            }
            str[index++] = ' ';
        }
        str[index - 1] = '\0';
        ret[index1++] = str;
        return;
    }

    if (failArr[s - src] == 1) {
        return;        
    }


    for (i = 0; i < wordDictSize; i++) {
        
        if (s == src) {
            memset(failArr, 0, sizeof(failArr));
        }
        len = strlen(wordDict[i]);
        if (failArr[s - src + len] == 1) {
            fail++;
            continue;
        }
        if (isSame(s, wordDict[i], len)) {
            tmp[tmpIndex] = len;
            isSub(src, &s[len], wordDict, wordDictSize, tmp, tmpIndex + 1);
        } else {
            fail++;
        }
    }
    if (fail == wordDictSize) {
        failArr[s - src] = 1;
    }

    return;
}
int compare(void *a, void *b) {
    return strlen(*(char**)a) - strlen(*(char**)b);
}
char ** wordBreak(char * s, char ** wordDict, int wordDictSize, int* returnSize){
   // 先检查一遍，字符类数是否够
    int alphS = 0;
    int alphW = 0;
    char *p = s;
    int i;
    int *tmp = NULL;
    int tmpIndex = 0;


    while (*p) {
        alphS = alphS | (1 << (*p - 'a'));
        p++;
    }

    for (i = 0; i < wordDictSize; i++) {
        p = wordDict[i];
        while (*p) {
            alphW = alphW | (1 << (*p - 'a'));
            p++;
        }
    }

    if ((alphS & alphW) < alphS) {
        *returnSize = 0;
        return NULL;
    }

    qsort(wordDict, wordDictSize, sizeof(char*), compare);

    memset(failArr, 0, sizeof(failArr));

    ret = (char**)malloc(sizeof(char*) * MAX_LEN);
    index1 = 0;

    tmp = (int*)malloc(sizeof(int) * MAX_LEN);



    isSub(s, s, wordDict, wordDictSize, tmp, 0);
    *returnSize = index1;

    return ret;
}




```