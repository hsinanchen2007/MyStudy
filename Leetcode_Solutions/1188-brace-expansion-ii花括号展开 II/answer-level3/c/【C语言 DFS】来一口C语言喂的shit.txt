```c
#define HASH_SIZE 10007
#define INF 0x7fffffff
#define SEED 131

typedef struct HashMap_t {
    char* arr[HASH_SIZE];
} HashMap;

HashMap g_hashMap;

static inline unsigned int Hash1(unsigned int key)
{
    return key % HASH_SIZE;
}

static inline unsigned int Hash2(unsigned int key)
{
    return 1 + (key % (HASH_SIZE - 1));
}

static inline unsigned int CalcHashKey(unsigned int hash1, unsigned int hash2, unsigned int i)
{
    unsigned int hashX = (hash1 + (unsigned long long)i * (unsigned long long)hash2 % HASH_SIZE) % HASH_SIZE;
    return hashX;
}

static inline unsigned int BKDRHash(char *str)
{
    if (!str) {
        return -1;
    }
    unsigned int seed = SEED;
    unsigned int hash = 0;

    unsigned char *p = (unsigned char *)str;
    while (*p) {
        hash = hash * seed + (*p++);
    }
    return hash % HASH_SIZE;
}

static inline void HashInsert(HashMap* hashMap, char* str)
{
    if (!hashMap || !str) {
        return ;
    }
    unsigned int key = BKDRHash(str);
    unsigned int hash1 = Hash1(key);
    unsigned int hash2 = Hash2(key);
    unsigned int hashX;
    for (int i = 0;;++i) {
        hashX = CalcHashKey(hash1, hash2, i);
        if (hashMap->arr[hashX] == NULL) {
            hashMap->arr[hashX] = str;
            return ;
        } else if (strcmp(hashMap->arr[hashX], str) == 0) {
            return ;
        }
    }
}

static inline bool HashFind(HashMap* hashMap, char* str) 
{
    if (!hashMap || !str) {
        return false;
    }
    unsigned int key = BKDRHash(str);
    unsigned int hash1 = Hash1(key);
    unsigned int hash2 = Hash2(key);
    unsigned int hashX;
    for (unsigned int i = 0;;++i) {
        hashX = CalcHashKey(hash1, hash2, i);
        if (hashMap->arr[hashX] == NULL) {
            return false;
        } else if (strcmp(hashMap->arr[hashX], str) == 0) {
            return true;
        }
    }
    return false;
}

static inline void HashInit(HashMap* hashMap)
{
    if (!hashMap) {
        return ;
    }
    memset(hashMap->arr, 0, sizeof(hashMap->arr));
}

#define SIZE 52
char g_cash[HASH_SIZE][SIZE];
int g_count;

static inline bool IsExistLeftBacket(char* expression)
{
    while (*expression) {
        if (*expression == '{') {
            return true;
        }
        ++expression;
    }
    return false;
}

static inline int Split(char* str, char* splitStr, char (*ret)[SIZE])
{
    char *q = strtok(str, splitStr);
    int count = 0;
    while(q) {
        strcpy(ret[count], q);
        ++count;
        q = strtok(NULL, ","); 
    }
    return count;
}

void Dfs(char* expression)
{
    if (expression == NULL) {
        return ;
    }
    if (!IsExistLeftBacket(expression)) {
        if (!HashFind(&g_hashMap, expression)) {
            // puts("XXXXXXXXXXXXXXX");
            // puts(expression);
            // puts("XXXXXXXXXXXXXXX");
            strcpy(g_cash[g_count], expression);
            HashInsert(&g_hashMap, g_cash[g_count]);
            ++g_count;
        }
        return ;
    }

    char leftCash[SIZE];
    char rightCash[SIZE];
    char middleCash[SIZE];
    memset(leftCash, 0, sizeof(leftCash));
    memset(rightCash, 0, sizeof(rightCash));
    memset(middleCash, 0, sizeof(middleCash));
    int left;
    int right;
    int i;
    int len = strlen(expression);

    for (i = 0; i < len && expression[i] != '}'; ++i) {
        if (expression[i] == '{') {
            left = i;
        }
    }
    right = i;
    strncpy(leftCash, expression, left);
    leftCash[left] = '\0';
    strcpy(rightCash, expression + right + 1);
    strncpy(middleCash, expression + left + 1, right - left - 1);
    middleCash[right - left - 1] = '\0';

    // puts("=========");
    // puts(expression);
    // puts(leftCash);
    // puts(middleCash);
    // puts(rightCash);

    char split[SIZE][SIZE];
    int splitCount = Split(middleCash, ",", split);
    for (i = 0; i < splitCount; ++i) {
        // puts(split[i]);
        char cash[SIZE];
        memset(cash, 0, sizeof(cash));
        strcpy(cash, leftCash);
        strcat(cash, split[i]);
        strcat(cash, rightCash);
        Dfs(cash);
    }
    // puts("=========");
}

int Cmp(const void* a, const void* b)
{
    char* aa = *(char**)a;
    char* bb = *(char**)b;
    return strcmp(aa, bb);
}

char ** braceExpansionII(char * expression, int* returnSize){
    if (expression == NULL) {
        *returnSize = 0;
        return NULL;
    }
    HashInit(&g_hashMap);
    g_count = 0;
    memset(g_cash, 0, sizeof(g_cash));
    Dfs(expression);
    *returnSize = g_count;
    char** ret = (char**)malloc(sizeof(char*) * g_count);
    int i;
    for (i = 0; i < g_count; ++i) {
        ret[i] = (char*)malloc(sizeof(char) * SIZE);
        strcpy(ret[i], g_cash[i]);
    }
    qsort(ret, g_count, sizeof(char*), Cmp);
    return ret;
}
```