```c
#define HASH_SIZE 10007
#define INF 0x7fffffff

typedef struct HashNode_t {
    int key;
    int value;
} HashNode;

typedef struct HashMap_t {
    HashNode arr[HASH_SIZE];
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
    int hash1 = Hash1(node->key);
    int hash2 = Hash2(node->key);
    int hashX;
    for (int i = 0;; ++i) {
        hashX = CalcHashKey(hash1, hash2, i);
        if (hashMap->arr[hashX].key == INF) {
            hashMap->arr[hashX] = *node;
            return ;
        } else if (hashMap->arr[hashX].key == node->key) {
            return ;
        }
    }
}

static inline HashNode* HashFind(HashMap* hashMap, int key)
{
    int hash1 = Hash1(key);
    int hash2 = Hash2(key);
    int hashX;
    for (int i = 0;; ++i) {
        hashX = CalcHashKey(hash1, hash2, i);
        if (hashMap->arr[hashX].key == INF) {
            return NULL;
        } else if (hashMap->arr[hashX].key == key) {
            return &hashMap->arr[hashX];
        }
    }
    return NULL;
}

static inline void HashInit(HashMap* hashMap)
{
    for (int i = 0; i < HASH_SIZE; ++i) {
        hashMap->arr[i].key = INF;
    }
}

int majorityElement(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return -1;
    }
    if (numsSize == 1) {
        return nums[0];
    }
    int count = numsSize / 2;
    HashInit(&g_hashMap);
    int i;
    HashNode *node = NULL;
    HashNode tmpNode;
    for (i = 0; i < numsSize; ++i) {
        node = HashFind(&g_hashMap, nums[i]);
        if (node) {
            ++node->value;
            if (node->value > count) {
                return node->key;
            } 
        } else {
            tmpNode.key = nums[i];
            tmpNode.value = 1;
            HashInsert(&g_hashMap, &tmpNode);
        }

    }
    return -1;
}

```