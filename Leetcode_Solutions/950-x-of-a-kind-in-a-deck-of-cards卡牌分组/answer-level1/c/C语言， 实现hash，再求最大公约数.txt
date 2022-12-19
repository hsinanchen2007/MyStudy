```c
#define HASH_SIZE 10007
#define INF 0x7fffffff

typedef struct HashNode_t {
    int key;
    int value;
} HashNode;

typedef struct HashMap_t {
    HashNode arr[HASH_SIZE];
    HashNode* record[HASH_SIZE];
    int count;
} HashMap;

HashMap g_hashMap;

static inline int Hash1(int key)
{
    return key % HASH_SIZE;
}

static inline int Hash2(int key)
{
    return 1 + (key % (HASH_SIZE - 1));
}

static inline int CalcHashKey(int hash1, int hash2, int i)
{
    int hashX = (hash1 + (long long)i * (long long)hash2 % HASH_SIZE) % HASH_SIZE;
    if (hashX < 0) {
        hashX += HASH_SIZE;
    }
    return hashX;
}

static inline void HashInsert(HashMap* hashMap, HashNode* node)
{
    if (!hashMap || !node) {
        return ;
    }
    int hash1 = Hash1(node->key);
    int hash2 = Hash2(node->key);
    int hashX;
    for (int i = 0;; ++i) {
        hashX = CalcHashKey(hash1, hash2, i);
        if (hashMap->arr[hashX].key == -1) {
            hashMap->arr[hashX].key = node->key;
            hashMap->arr[hashX].value = 1;
            hashMap->record[hashMap->count++] = &hashMap->arr[hashX];
            return ;
        } else if (hashMap->arr[hashX].key == node->key) {
            ++hashMap->arr[hashX].value;
            return ;
        }
    }
}

static inline HashNode* HashFind(HashMap* hashMap, int key)
{
    if (!hashMap) {
        return NULL;
    }
    int hash1 = Hash1(key);
    int hash2 = Hash2(key);
    int hashX;
    for (int i = 0;; ++i) {
        hashX = CalcHashKey(hash1, hash2, i);
        if (hashMap->arr[hashX].key == -1) {
            return NULL;
        } else if (hashMap->arr[hashX].key == key) {
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
    memset(hashMap->arr, -1, sizeof(hashMap->arr));
    memset(hashMap->record, 0, sizeof(hashMap->record));
    hashMap->count = 0;
}

HashMap g_hashMap;

int Gcd(int a, int b)
{
    int c;
    while (b) {
        c = a;
        a = b;
        b = c % b;
    }
    return a;
}

bool hasGroupsSizeX(int* deck, int deckSize){
    if (deck == NULL || deckSize == 0 || deckSize == 1) {
        return false;
    }
    HashInit(&g_hashMap);
    HashNode node;
    int i;
    for (i = 0; i < deckSize; ++i) {
        node.key = deck[i];
        HashInsert(&g_hashMap, &node);
    }

    int ret = g_hashMap.record[0]->value;
    for (i = 1; i < g_hashMap.count; ++i) {
        ret = Gcd(ret, g_hashMap.record[i]->value);
        if (ret == 1) {
            return false;
        }
    }

    return ret != 1;
}


```