### 解题思路
此处撰写解题思路

### 代码

```c
struct HashEntry
{
    char key[1000];
    int value[1000];
    int cnt;
    UT_hash_handle hh;
};

struct HashEntry *g_hashEntry = NULL;

static int Compare(const void *a, const void *b)
{
    return *(const char *)a - *(const char *)b;
}

static void AddToHash(char **strs, int strsSize, int *returnSize)
{
    struct HashEntry *node = NULL;
    char tmp[1000] = {0};
    for (int i = 0; i < strsSize; i++) {
        memset(tmp, 0, 1000);
        if (strs[i] != NULL) {
            strncpy(tmp, strs[i], strlen(strs[i]) + 1);
            qsort(tmp, strlen(tmp), sizeof(char), Compare);
            HASH_FIND_STR(g_hashEntry, tmp, node);
            if (node != NULL) {
                node->value[node->cnt++] = i;
            } else {
                node = (struct HashEntry *)malloc(sizeof(struct HashEntry));
                if (node == NULL) {
                    return;
                }
                memset(node, 0, sizeof(struct HashEntry));
                node->value[node->cnt++] = i;
                strncpy(node->key, tmp, strlen(tmp) + 1);
                (*returnSize)++;
                HASH_ADD_STR(g_hashEntry, key, node);
            }
        }
    }
}

static void ReleaseHashEntry(void)
{
    struct HashEntry *node = NULL;
    struct HashEntry *next = NULL;
    HASH_ITER(hh, g_hashEntry, node, next) {
        HASH_DEL(g_hashEntry, node);
    }
}

static char ***GetRes(char **strs, int strsSize, int *returnSize, int **returnColumnSizes)
{
    char ***res = NULL;
    res = (char ***)malloc(sizeof(char **) * strsSize);
    assert(res != NULL);
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    assert((*returnColumnSizes) != NULL);

    struct HashEntry *node = NULL;
    struct HashEntry *next = NULL;
    int index = 0;
    HASH_ITER(hh, g_hashEntry, node, next) {
        res[index] = (char **)malloc(sizeof(char *) * node->cnt);
        (*returnColumnSizes)[index] = node->cnt;
        int len = strlen(node->key);
        for (int i = 0; i < node->cnt; i++) {
            res[index][i] = strs[node->value[i]];
        }
        index++;
    }
    ReleaseHashEntry();
    return res;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    if (strs == NULL || strsSize == 0) {
        return NULL;
    }

    AddToHash(strs, strsSize, returnSize);
    return GetRes(strs, strsSize, returnSize, returnColumnSizes);
}
```