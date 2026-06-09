### 解题思路
难点在于几个：
1、C语言的HASH
2、C语言的多维数组数据处理
3、并查集本身
4、输出排序

### 代码

```c
#define MAX_EMAIL_ACOUNTS_SIZE  10000 
#define MAX_EMAIL_NAME_LENGTH   30
typedef struct {
    char key[MAX_EMAIL_NAME_LENGTH];
    int index;
    UT_hash_handle hh;
} Node;

int *g_setClass;

int FindSet(int index)
{
    if (index == g_setClass[index]) {
        return index;
    } 

    g_setClass[index] = FindSet(g_setClass[index]);
    return g_setClass[index];
}

int UnionSet(int index1, int index2)
{
    int set1 = FindSet(index1);
    int set2 = FindSet(index2);

    if (set1 < set2) {
        g_setClass[set2] = set1;
    } else {
        g_setClass[set1] = set2;
    }

    return g_setClass[set1];
}

void UpdateUnionSet(Node *hash, int index)
{
    Node *curr = NULL;
    Node *iter = NULL;
    HASH_ITER(hh, hash, curr, iter)
    {
        int currIndex = FindSet(curr->index);
        if (currIndex == index) {
            curr->index = index;
        }
    }

    return;
}

void HashScan(Node *hash, const char *caller)
{
    return;
    Node *curr = NULL;
    Node *iter = NULL;
    HASH_ITER(hh, hash, curr, iter)
    {
        printf("[%s][%s]:%d\n", caller, curr->key, curr->index);
    }
    printf("***********************************************\n");

    return;
}

Node *HashAdd(Node *hash, char *key, int index)
{
    Node *node = NULL;
    HASH_FIND_STR(hash, key, node);
    if (node == NULL) {
        node = (Node *)malloc(sizeof(Node));
        memset(node, 0, sizeof(Node));
        strcpy(node->key, key);
        node->index = FindSet(index);
        HASH_ADD_STR(hash, key, node);
        HashScan(hash, __FUNCTION__);
        return hash;
    }

    // update the index to the root index
    node->index = UnionSet(node->index, index);
    UpdateUnionSet(hash, node->index);
    HashScan(hash, __FUNCTION__);
    return hash;
}

void InitialSetClass(int accountsSize)
{
    g_setClass = (int *)malloc(sizeof(int) * accountsSize);
    memset(g_setClass, 0, sizeof(int) * accountsSize);
    for (int i = 0; i < accountsSize; i++) {
        g_setClass[i] = i;
    }

    return;
}

Node *HashAddAndUnion(Node * hash, char *** accounts, int accountsSize, int* accountsColSize)
{
    for (int i = 0; i < accountsSize; i++) {
        for (int j = 1; j < accountsColSize[i]; j++) {
            hash = HashAdd(hash, (char *)accounts[i][j], i);
        }
    }

    HashScan(hash, __FUNCTION__);
    return hash;
}

typedef struct {
    int hashIndex;
    int rowIndex;
    int colIndex;
    int used;
} IndexMap;

int InitialIndexMap(Node * hash, IndexMap *indexMap)
{
    Node *curr = NULL;
    Node *iter = NULL;
    int index = 0;
    HASH_ITER(hh, hash, curr, iter)
    {
        if (indexMap[curr->index].used == 0) {
            indexMap[curr->index].rowIndex = index;
            indexMap[curr->index].hashIndex = curr->index;
            indexMap[curr->index].used = 1;
            index++;
        }
    }

    return index;
}

void ShowAns(char ***ans, int rowSize, int *colSize)
{
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize[i]; j++) {
            printf("%s,", ans[i][j]);
        }
        printf("\n");
    }

    return;
}

char ***HashScanAndMerge(Node * hash, int* returnSize, int** returnColumnSizes, char *** accounts)
{
    Node *curr = NULL;
    Node *iter = NULL;
    int row = 0;
    int col = 0;
    char ***ans = (char ***)malloc(sizeof(char **) * MAX_EMAIL_ACOUNTS_SIZE);
    memset(ans, 0, sizeof(char **) * MAX_EMAIL_ACOUNTS_SIZE);

    int *retCol = (int *)malloc(sizeof(int) * MAX_EMAIL_ACOUNTS_SIZE);
    memset(retCol, 0, sizeof(int) * MAX_EMAIL_ACOUNTS_SIZE);

    IndexMap *indexMap = (IndexMap *)malloc(sizeof(IndexMap) * MAX_EMAIL_ACOUNTS_SIZE);
    memset(indexMap, 0, sizeof(IndexMap) * MAX_EMAIL_ACOUNTS_SIZE);

    *returnSize = InitialIndexMap(hash, indexMap); 

    HASH_ITER(hh, hash, curr, iter)
    {
        // need a new space
        char *mail = (char *)malloc(sizeof(char) * MAX_EMAIL_NAME_LENGTH);
        strcpy(mail, curr->key);
        mail[strlen(curr->key)] = '\0';
        row = indexMap[curr->index].rowIndex;
        col = indexMap[curr->index].colIndex;
        if (ans[row] == NULL) {
            ans[row] = (char **)malloc(sizeof(char *) * MAX_EMAIL_ACOUNTS_SIZE);
            memset(ans[row], 0, sizeof(char *) * MAX_EMAIL_ACOUNTS_SIZE);
            char *name = (char *)malloc(sizeof(char) * MAX_EMAIL_NAME_LENGTH);
            strcpy(name, accounts[curr->index][0]);
            name[strlen(accounts[curr->index][0])] = '\0';
            ans[row][col++] = name;
            ans[row][col++] = mail;
        } else {
            ans[row][col++] = mail;
        }
        indexMap[curr->index].colIndex = col;
        retCol[row] = col;
    }

    *returnColumnSizes = retCol;
    return ans;
}

int SortCmp(const void *p1, const void *p2)
{
    char **s1 = (char **)p1;
    char **s2 = (char **)p2;

    return strcmp(*s1, *s2);
}

void SortAns(char ***ans, int rowSize, int *colSize)
{
    for (int i = 0; i < rowSize; i++) {
        qsort(&(ans[i][1]), (colSize[i] - 1), sizeof(ans[i][1]), SortCmp);
    }

    return;
}

void FreeMiddleResource(Node *hash)
{
    Node *curr = NULL;
    Node *iter = NULL;
    HASH_ITER(hh, hash, curr, iter)
    {
        free(curr);
        curr = NULL;
    }

    return;
}

char *** accountsMerge(char *** accounts, int accountsSize, int* accountsColSize, int* returnSize, int** returnColumnSizes)
{
    // define return ans, and initial
    char ***ans;
    Node *emailHash = NULL;

    // Initial the set class
    InitialSetClass(accountsSize);

    // Hash the account, add and union the set
    emailHash = HashAddAndUnion(emailHash, accounts, accountsSize, accountsColSize);

    // Scan, merge account and sort by name 
    ans = HashScanAndMerge(emailHash, returnSize, returnColumnSizes, accounts);

    // Sort the ans
    SortAns(ans, *returnSize, *returnColumnSizes);

    // Free middle alloc resouce
    FreeMiddleResource(emailHash);

    return ans;
}
```