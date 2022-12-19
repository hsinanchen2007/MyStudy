### 解题思路
利用Hash表快速搜索

### 代码

```c
typedef struct tagHASH_ELEMENT_S {
    int nVal;
    int nIndex;
} HASH_ELEMET_S;


typedef struct tagHASH_NODE_S {
    HASH_ELEMET_S *pElement;
    struct tagHASH_NODE_S  *pNext;
} HASH_NODE_S;

typedef struct tagHASH_MAP_S {
    int nHashSize;
    int nHashNowSize;
    HASH_NODE_S *pHashHead;
} HASH_MAP_S;

#define GET_HASH_INDEX(val, max) (val < 0 ? (val*-1 % max) : (val %max))

HASH_MAP_S* initHashMap(int nSize) 
{
    HASH_MAP_S *pHashMap = (HASH_MAP_S*)malloc(sizeof(HASH_MAP_S)); 
    if (!pHashMap) {
        return NULL;
    } 
    pHashMap->nHashSize = nSize;
    pHashMap->nHashNowSize = 0;
    pHashMap->pHashHead = (HASH_NODE_S*)calloc(pHashMap->nHashSize, sizeof(HASH_NODE_S));
    if (!pHashMap->pHashHead) {
        free(pHashMap);
        return NULL;
    }
    return pHashMap;
}

int insertHashMap(HASH_MAP_S *pHashMap, int nVal, int nArrIndex) 
{
    pHashMap->nHashNowSize++;
    int nIndex = GET_HASH_INDEX(nVal, pHashMap->nHashSize);
    HASH_NODE_S *pInsertNode = &pHashMap->pHashHead[nIndex];

    if (pInsertNode->pElement) {
        HASH_NODE_S *newNode = (HASH_NODE_S*)calloc(1, sizeof(HASH_NODE_S));
        if (!newNode) {
            return -1;
        }
        while (pInsertNode->pNext) {
            pInsertNode = pInsertNode->pNext;
        }
        pInsertNode->pNext = newNode;
        pInsertNode = newNode;
    }

    HASH_ELEMET_S *newElement = (HASH_ELEMET_S*)malloc(sizeof(HASH_ELEMET_S));
    if (!newElement) {
        return -1;
    }
    newElement->nVal = nVal;
    newElement->nIndex = nArrIndex;
    pInsertNode->pElement = newElement;
    return 0;
}

int findHashMap(HASH_MAP_S *pHashMap, int nVal, int firstIndex) {
    int nIndex = GET_HASH_INDEX(nVal , pHashMap->nHashSize);
    HASH_NODE_S *pNode = &pHashMap->pHashHead[nIndex];

    do {
        if (pNode->pElement && pNode->pElement->nVal == nVal && firstIndex != pNode->pElement->nIndex) {
            return pNode->pElement->nIndex;
        }
    } while (pNode = pNode->pNext);
    return -1;
}

void freeHashMap(HASH_MAP_S *pHashMap) {
    for (int i = 0; i < pHashMap->nHashSize; i++) {
        HASH_NODE_S *pNode = &pHashMap->pHashHead[i];
        if (pNode->pElement) {
            free(pNode->pElement);
        }
        pNode = pNode->pNext;
        while (pNode) {
            if (pNode->pElement) {
                free(pNode->pElement);
            }
            HASH_NODE_S *pThisNode = pNode;
            pNode = pNode->pNext;
            free(pThisNode);
        }
    }
    free(pHashMap->pHashHead);
    free(pHashMap);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    if (!nums || numsSize < 2 || !returnSize) {
        return NULL;
    }

    HASH_MAP_S* hashMap = initHashMap(1001);
    if (!hashMap) {
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        int index = findHashMap(hashMap, target - nums[i], i);
        if (index != -1) {
            int *result = (int*)malloc(sizeof(int)*2);
            result[0] = i;
            result[1] = index;
            freeHashMap(hashMap);
            *returnSize = 2;
            return result;
        }
        insertHashMap(hashMap, nums[i], i);
    }
    
    freeHashMap(hashMap);
    return NULL;
}
```