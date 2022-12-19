```
/*解题思路：
    1.先排序字符串，以判断是否是异位词；
    2.在hashtable中存放异位词的从小到大的字符串;
    3.在ht中查找，以此判断是否需要创建result的新行；
    4.存在ht中，则通过Str->id插入字符串即可；
    5.不存在ht中，则在result中创建新行； 
*/
#define STR_MAX_LEN 10000
static int compare(const void* x, const void* y)
{
    return *(char*)x - *(char*)y;
}

struct Str {
    char key_str[STR_MAX_LEN];
    int id;
    UT_hash_handle hh;
};

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    if (strs == NULL || strsSize < 0) {
        return NULL;
    }
    struct Str *keyStrsHash = NULL, *str = NULL;
    char ***result = (char ***)malloc(sizeof(char **) * strsSize);
    char **sortedStrs = (char **)malloc(sizeof(char *) * strsSize);
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * strsSize);

    for (int i = 0; i < strsSize; i++) {
        int len = strlen(strs[i]);
        sortedStrs[i] = (char*)malloc(len + 1);
        (void)strcpy(sortedStrs[i], strs[i]);
        qsort(sortedStrs[i], len, sizeof(char), compare);
        
        HASH_FIND_STR(keyStrsHash, sortedStrs[i], str);
        if (!str) {
            str = (struct Str*)malloc(sizeof(struct Str));
            strcpy(str->key_str, sortedStrs[i]);
            str->id = *returnSize;
            HASH_ADD_STR(keyStrsHash, key_str, str);

            result[*returnSize] = (char**)malloc(sizeof(char*) * strsSize);
            result[*returnSize][0] = (char*)malloc(len + 1);
            strcpy(result[*returnSize][0], strs[i]);

            (*returnColumnSizes)[*returnSize] = 1;
            (*returnSize)++;
        } else {
            int row = str->id;
            int col = (*returnColumnSizes)[row];
            result[row][col] = (char*)malloc(len + 1);
            strcpy(result[row][col], strs[i]);
            ((*returnColumnSizes)[row])++;
        }
    }

    HASH_CLEAR(hh, keyStrsHash);
    for (int i = 0; i < strsSize; i++) {
            free(sortedStrs[i]);
    }
    return result;
}
```
