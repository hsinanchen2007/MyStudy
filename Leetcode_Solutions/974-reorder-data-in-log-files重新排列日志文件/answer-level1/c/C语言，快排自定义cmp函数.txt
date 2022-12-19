### 解题思路
细节比较多，需要仔细考虑

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp (const void *a, const void *b) {
    char *str1 = *((char **)a);
    char *str2 = *((char **)b);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int end1, end2;
    int flag = 0;
    int i = 0, j = 0;
    while(i < len1 && str1[i] != ' ') {
        i++;
    }
    end1 = i++;
    while(j < len2 && str2[j] != ' ') {
        j++;
    }
    end2 = j++;
    // str1是数字，str2是字符串
    if (i < len1 && j < len2 && str1[i] <= '9' && str2[j] >= 'a') {
        return 1;
    }
    // str1是字符串，str2是数字
    if (i < len1 && j < len2 && str1[i] >= 'a' && str2[j] <= '9') {
        return -1;
    }
    // 两个都是字符串
    if (i < len1 && j < len2 && str1[i] >= 'a' && str2[j] >= 'a') {
        while (i < len1 && j < len2) {
            if (str1[i] < str2[j]) {
                return -1;
            } else if (str1[i] > str2[j]){
                return 1;
            }
            i++, j++;
        }
        flag = 1;
    }
    if (flag == 1) {
        i = 0, j = 0;
        while(i < end1 && j < end2) {
            if (str1[i] < str2[j]) {
                return -1;
            } else if (str1[i] > str2[j]) {
                return 1;
            }
        }
    }
    // 两个都是数字
    return 0;
}
char ** reorderLogFiles(char ** logs, int logsSize, int* returnSize){
    *returnSize = logsSize;
    qsort(logs, logsSize, sizeof(char **), cmp);
    return logs;
}
```