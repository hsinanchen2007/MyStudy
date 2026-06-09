### 解题思路
1. 遍历digits的每一位，保存在str[idx]。
2. 递归idx+1。
3. idx为strlen(digits)时保存结果。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


char map[8][4] = {
    {'a','b','c'},
    {'d','e','f'},
    {'g','h','i'},
    {'j','k','l'},
    {'m','n','o'},
    {'p','q','r','s'},
    {'t','u','v'},
    {'w','x','y','z'},
};


void backtrace(char *str, char *digits, int idx, char ***result, int *curSize, int *curIdx) {
    if (idx == strlen(digits)) {
        if (*curIdx >= *curSize) {
            *curSize *= 2;
            *result = realloc(*result, sizeof(char*) * (*curSize));//////
        }

        char *ret = (char*)malloc(sizeof(char) * (strlen(digits)+1));
        strcpy(ret, str);
        ret[strlen(digits)] = 0;

        (*result)[*curIdx] = ret;
        *curIdx += 1;
        return;
    }

    int i;
    for (i=0; i<4; i++) {
        char tmp = map[digits[idx]-'2'][i];
        if (tmp == 0) continue;
        str[idx] = tmp;
        backtrace(str, digits, idx+1, result, curSize, curIdx);
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    if (!digits || strlen(digits) == 0) { ////////////""
        *returnSize = 0;
        return NULL;
    }

    int curSize = 3;
    int curIdx = 0;
    int len = strlen(digits);
    char **result = (char**)malloc(sizeof(char*) * curSize);

    char str[len+1];
    (void)memset(str, 0, sizeof(char)*(len+1));
    backtrace(str, digits, 0, &result, &curSize, &curIdx);

    *returnSize = curIdx;
    return result;
}
```