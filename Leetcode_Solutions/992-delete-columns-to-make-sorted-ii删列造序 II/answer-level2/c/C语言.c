### 解题思路
此处撰写解题思路

### 代码

```c
int IsWordsOrder(char ** A, int ASize)
{
    for (int i = 0; i < ASize - 1; i++) {
        int cmp = strcmp(A[i], A[i + 1]);
        if (cmp > 0) {
            return -1;
        }
    }
    return 1;
}

int IsCharOrder(char **A, int ASize, int col)
{
    int same = 0;
    for (int i = 0; i < ASize - 1; i++) {
        int cmp =strncmp(A[i], A[i + 1], col + 1);
        if (cmp > 0) {
            return -1;
        } else if (cmp == 0) {
            same = 1;
        }
    }
    if (same == 1) {
        return 0;
    }
    return 1;
}

void Fullfill(char **A, int ASize, int col)
{
    for (int i = 0; i < ASize; i++) {
        memmove(A[i] + col, A[i] + col + 1, strlen(A[i]) - col);
    }
}

int minDeletionSize(char ** A, int ASize)
{
    if (ASize == 0) {
        return 0;
    }

    char **AA = (char **)malloc(sizeof(char *) * (ASize + 1));
    memset(AA, 0, sizeof(char *) * (ASize + 1));
    for (int i = 0; i < ASize; i++) {
        if (AA[i] == NULL) {
            AA[i] = (char *)malloc(sizeof(char) * (strlen(A[i]) + 1));
            memset(AA[i], 0, sizeof(char) * (strlen(A[i]) + 1));
        }
        memcpy(AA[i], A[i], strlen(A[i]));
        AA[i][strlen(A[i])] = '\0';
    }
    // 遍历单词的每一个字符，第一个字符，看是否全部有序，如已字典序，结束，返回遍历次数
    // 如非字典序，继续遍历第二个字符，看似可以递归？
    int ans = 0;
    // 单个单词的长度
    int wordSize  = strlen(AA[0]);
    int skip = 0;
    for (int i = 0; i < wordSize; i++) {
        // 整体思路：先比较整个单词，再逐列进行比较
        // 比较单词，若已经全部有序，则直接返回ans
        if (IsWordsOrder(AA, ASize) == 1) {
            return ans;
        }

        // 逐个单词字符比较：若严格升序，返回1，若有序但存在想通过字符，则返回0，若无序，则返回-1
        // 对于严格升序，直接返回ans
        // 对于升序且存有相同字符场景，当前列保留，继续比较下一列，直到找到非此类返回值
        // 对于无序，直接删除当前列，进入下一轮比较
        int ret = IsCharOrder(AA, ASize, i - skip);
        if (ret == 1) {
            return ans;
        }
        if (ret == 0) {
            // 保留本列，继续遍历下一列
            continue;

        } else if (ret == -1) {
            // 删除本列
            Fullfill(AA, ASize, i - skip);
            skip++;
            ans++;
        }
    }

    return ans;
}
```