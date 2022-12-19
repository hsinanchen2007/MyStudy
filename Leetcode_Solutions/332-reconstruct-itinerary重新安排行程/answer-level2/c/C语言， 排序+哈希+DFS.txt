![image.png](https://pic.leetcode-cn.com/55573fec81ea6781854aab7e7652be05eaa2b9dc253599eb83df28b0485f7e89-image.png)


```c
#define SIZE 105
#define HASH_SIZE 1003
#define INF 0x7fffffff
#define SEED 131

typedef struct HashNode_t {
    char* key;
    char* toPlace[SIZE];
    int count;
    int toPlaceVis[SIZE];
} HashNode;

typedef struct HashMap_t {
    HashNode arr[HASH_SIZE];
} HashMap;

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

static inline void HashInsert(HashMap* hashMap, HashNode* node)
{
    if (!hashMap || !node) {
        return ;
    }
    unsigned int key = BKDRHash(node->key);
    unsigned int hash1 = Hash1(key);
    unsigned int hash2 = Hash2(key);
    unsigned int hashX;
    for (int i = 0;; ++i) {
        hashX = CalcHashKey(hash1, hash2, i);
        if (hashMap->arr[hashX].key == NULL) {
            hashMap->arr[hashX] = *node;
            return ;
        } else if (strcmp(hashMap->arr[hashX].key, node->key) == 0) {
            return ;
        }
    }
}

static inline HashNode* HashFind(HashMap* hashMap, char* str)
{
    if (!hashMap || !str) {
        return NULL;
    }
    unsigned int key = BKDRHash(str);
    unsigned int hash1 = Hash1(key);
    unsigned int hash2 = Hash2(key);
    unsigned int hashX;
    for (unsigned int i = 0;; ++i) {
        hashX = CalcHashKey(hash1, hash2, i);
        if (hashMap->arr[hashX].key == NULL) {
            return NULL;
        } else if (strcmp(hashMap->arr[hashX].key, str) == 0) {
            return &hashMap->arr[hashX];
        }
    }
    return NULL;
}

static inline void HashInit(HashMap* hashMap)
{
    if (!hashMap) {
        return ;
    }
    for (int i = 0; i < HASH_SIZE; ++i) {
        hashMap->arr[i].key = NULL;
    }
}

int Cmp(const void* a, const void* b)
{
    char** aa = *(char***)a;
    char** bb = *(char***)b;
    int ret = strcmp(aa[0], bb[0]);
    if (ret) {
        return ret;
    }
    return strcmp(aa[1], bb[1]);
}

#define MAX_SIZE 10005
#define NAME_SIZE 5

char* g_ret[MAX_SIZE];
int g_index;
HashMap g_hashMap;

bool Dfs(char *start, int index)
{
    if (index == g_index - 1) {
        g_ret[index] = start;
        return true;
    }
    HashNode* p = HashFind(&g_hashMap, start);
    if (p == NULL) {
        return false;
    }
    g_ret[index] = start;

    int i;
    for (i = 0; i < p->count; ++i) {
        if (!p->toPlaceVis[i]) {
            p->toPlaceVis[i] = true;
            if (Dfs(p->toPlace[i], index + 1)) {
                return true;
            }
            p->toPlaceVis[i] = false;
        }
    }
    return false;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findItinerary(char *** tickets, int ticketsSize, int* ticketsColSize, int* returnSize){
    if (tickets == NULL || ticketsSize == 0 || ticketsColSize[0] != 2) {
        *returnSize = 0;
        return NULL;
    }
    g_index = 0;
    HashInit(&g_hashMap);
    memset(g_ret, 0, sizeof(g_ret));
    qsort(tickets, ticketsSize, sizeof(char**), Cmp);

    int i;
    HashNode node;
    node.count = 1;
    memset(node.toPlaceVis, 0, sizeof(node.toPlaceVis));
    HashNode* p = NULL;
    HashNode* start = NULL;
    for (i = 0; i < ticketsSize; ++i) {
        p = HashFind(&g_hashMap, tickets[i][0]);
        if (p) {
            p->toPlace[p->count++] = tickets[i][1];
        } else {
            node.key = tickets[i][0];
            node.toPlace[0] = tickets[i][1];
            HashInsert(&g_hashMap, &node);
        }
    }

    g_index = ticketsSize + 1;
    Dfs("JFK", 0);
    char** ret = (char**)malloc(g_index * sizeof(char*));
    for (i = 0; i < g_index; ++i) {
        if (g_ret[i] == NULL) {
            break;
        }
        ret[i] = (char*)malloc(sizeof(char) * NAME_SIZE);
        strcpy(ret[i], g_ret[i]);
    }
   
    *returnSize = g_index;
    return ret;
}

```