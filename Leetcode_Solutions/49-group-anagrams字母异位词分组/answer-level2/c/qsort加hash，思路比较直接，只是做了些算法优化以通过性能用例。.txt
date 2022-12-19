思路：
    1）利用hash统计检查两个字符串是否是异位词；
    2）对原始字符串数组，按字符串长度进行快排；
    3）优化点：对于指定的字符串，在已归类的字符串分组中查找是否存在异位词时，从*index - 1开始向前查找，如果发现长度不相等，说明当前字符串是新的异位词分组的第一个字符串，则结束查找。（PS：这一点优化很重要，否则性能用例过不了！）

代码：

#define SIZE    26
#define MAX_COLUMN_SIZE     50

int Comp(const void *a, const void *b)
{
  return strlen(*(char **)b) - strlen(*(char **)a);
}

bool IsAnagrams(const char *str1, int len1, const char *str2, int len2)
{
    int hash[SIZE] = {0};
    int i;

    if (len1 != len2) {
        return false;
    }

    for (i = 0; i < len1; i++) {
        hash[str1[i] - 'a']++;
        hash[str2[i] - 'a']--;
    }

    for (i = 0; i < SIZE; i++) {
        if (hash[i] != 0) {
            return false;
        }
    }

    return true;
}
void AddStr(char **arr, int *index, char *str)
{
    arr[*index] = str;
    (*index)++;

    return;
}

void AddToRes(char ***res, int *index, int *columnSize, char *str, int len)
{
    int i;
    bool match = false;
    
    for (i = *index - 1; i >= 0; i--) {
        if (res[i][0] == NULL) {
            break;
        }

        if (strlen(res[i][0]) != len) {
            break;
        }
        if (IsAnagrams(res[i][0], len, str, len)) {
            match = true;
            break;
        }
    }
    
    if (!match) {
        i = *index;
        res[i] = (char **)malloc(sizeof(char *) * MAX_COLUMN_SIZE);
        memset(res[i], 0, sizeof(char *) * MAX_COLUMN_SIZE);
        (*index)++;
    }
    
    AddStr(res[i], &columnSize[i], str);

    return;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    char ***res = NULL;
    int *columnSize = NULL;
    int i, j;
    int len;

    res = (char ***)malloc(sizeof(char **) * strsSize);
    memset(res, 0, sizeof(char **) * strsSize);
    *returnSize = 0;

    columnSize = (int *)malloc(sizeof(int) * strsSize);
    memset(columnSize, 0, sizeof(int) * strsSize);
    *returnColumnSizes = columnSize;

    qsort(strs, strsSize, sizeof(strs[0]), Comp);

    for (i = 0; i < strsSize; i++) {
        AddToRes(res, returnSize, columnSize, strs[i], strlen(strs[i]));
    }

    return res;
}

