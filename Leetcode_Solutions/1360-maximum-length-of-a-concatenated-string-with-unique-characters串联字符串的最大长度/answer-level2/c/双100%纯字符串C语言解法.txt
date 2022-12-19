![image.png](https://pic.leetcode-cn.com/bc919c500b959c897ca403682d1503f78713b7b25d1107e6a65eedf6a84f05fd-image.png)

```
int StrLenCmp(const void *a, const void *b)
{
    return strlen(*(char **)b) - strlen(*(char **)a);
}

int HasMoreSameChar(char *arr)
{
    int sameCharRec[26] = {0};

    while (*arr != '\0') {
        if (sameCharRec[*arr - 'a'] == 0) {
            sameCharRec[*arr - 'a']++;
        } else {
            return 1;
        }
        arr++;
    }

    return 0;
}

int maxLength(char **arr, int arrSize)
{
    int monoMaxLen = 0;
    char *startChar = (char *)malloc(sizeof(char) * 27); // 26个字母 + 1空位
    memset(startChar, '\0', sizeof(char) * 27);

    // 利用快排把长度较长的字符串排在前面
    qsort(arr, arrSize, sizeof(char *), StrLenCmp);

    // 两重遍历逐个比较，满足单词内不重复字母且与已组合的单词串字母不重复这两个条件时，合并新单词至已组合单词串中
    for (int i = 0; i < arrSize; i++) {
        // 如果目标字段就有重复的字母，直接pass掉
        if (HasMoreSameChar(arr[i]) == 1) {
            continue;
        }
        // startChar 是每一个i遍历的组合单词串
        strncpy(startChar, arr[i], strlen(arr[i]) + 1);

        for (int j = 0; j < arrSize; j++) {
            // strcspn是找startChar中第一个有arr[j]种字符的位置，如果不存在重复字母，这个位置应该在startChar尾巴上，即strlen(startChar)
            if (i != j && HasMoreSameChar(arr[j]) == 0 && strlen(startChar) == strcspn(startChar, arr[j])) {
                // 满足要求，则组合成一个更长的新串
                startChar = strcat(startChar, arr[j]);
            }
        }
        // 找最大
        monoMaxLen = strlen(startChar) > monoMaxLen ? strlen(startChar) : monoMaxLen;
        memset(startChar, '\0', sizeof(char) * 27);
    }
    return monoMaxLen;
}
```
