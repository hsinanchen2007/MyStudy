``` c []

typedef struct tagLRUCache {
    int key;
    int value;
    struct tagLRUCache* prev;
    struct tagLRUCache* next;
} LRUCache;

typedef struct tagLRUCacheTbl {
    int key;
    LRUCache* cache;
    struct tagLRUCacheTbl* next;
} LRUCacheTbl;

#define HASH_NUM 163
#define HASH(key) ((key) % HASH_NUM)

LRUCacheTbl* g_LRUCacheHashHead = NULL;
LRUCache* g_LRUCacheHead = NULL;
LRUCache* g_LRUCacheTail = NULL;

int g_LRUCacheNum = 0;
int g_LRUCacheCnt = 0;

LRUCache* lRUCacheCreate(int capacity) {
    if (capacity == 0)
    {
        return NULL;
    }
    g_LRUCacheCnt = 0;
    g_LRUCacheNum = capacity;
    g_LRUCacheHashHead = (LRUCacheTbl*)malloc(HASH_NUM * sizeof(LRUCacheTbl));
    (void)memset(g_LRUCacheHashHead, 0, HASH_NUM * sizeof(LRUCacheTbl));

    g_LRUCacheHead = (LRUCache*)malloc(sizeof(LRUCache));
    g_LRUCacheTail = (LRUCache*)malloc(sizeof(LRUCache));
    (void)memset(g_LRUCacheHead, 0, sizeof(LRUCache));
    (void)memset(g_LRUCacheTail, 0, sizeof(LRUCache));
    g_LRUCacheHead->next = g_LRUCacheTail;
    g_LRUCacheTail->prev = g_LRUCacheHead;
    return g_LRUCacheHead;
}

int lRUCacheGet(LRUCache* obj, int key) {
    int hash_key = HASH(key);
    LRUCache* pPrevCache = NULL;
    LRUCache* pNextCache = NULL;
    LRUCacheTbl* pLRUCacheTbl = g_LRUCacheHashHead[hash_key].next;
    if (key < 0)
        return -1;

    while (pLRUCacheTbl != NULL)
    {
        if (pLRUCacheTbl->key == key)
        {
            pPrevCache = pLRUCacheTbl->cache->prev;
            pNextCache = pLRUCacheTbl->cache->next;
            pPrevCache->next = pNextCache;
            pNextCache->prev = pPrevCache;

            pPrevCache = g_LRUCacheHead;
            pNextCache = g_LRUCacheHead->next;
            pLRUCacheTbl->cache->next = pNextCache;
            pLRUCacheTbl->cache->prev = pPrevCache;
            pNextCache->prev = pLRUCacheTbl->cache;
            pPrevCache->next = pLRUCacheTbl->cache;
            return pLRUCacheTbl->cache->value;
        }
        pLRUCacheTbl = pLRUCacheTbl->next;
    }
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    int hash_key = HASH(key);
    LRUCache* pNewCache = NULL;
    LRUCache* pPrevCache = NULL;
    LRUCache* pNextCache = NULL;
    LRUCache* pDelCache = NULL;
    LRUCacheTbl* pLRUCacheTbl = g_LRUCacheHashHead[hash_key].next;
    LRUCacheTbl* pLRUCacheTblPre = &g_LRUCacheHashHead[hash_key];
    LRUCacheTbl* pLRUCacheTblNew = NULL;
    int i = 0;
    while (pLRUCacheTbl != NULL)
    {
        if (pLRUCacheTbl->key == key)
        {
            if (pLRUCacheTbl->cache != g_LRUCacheHashHead[hash_key].next)
            {
                pPrevCache = pLRUCacheTbl->cache->prev;
                pNextCache = pLRUCacheTbl->cache->next;
                pPrevCache->next = pNextCache;
                pNextCache->prev = pPrevCache;

                pLRUCacheTbl->cache->key = key;
                pLRUCacheTbl->cache->value = value;
                pPrevCache = g_LRUCacheHead;
                pNextCache = g_LRUCacheHead->next;
                pLRUCacheTbl->cache->next = pNextCache;
                pLRUCacheTbl->cache->prev = pPrevCache;
                pNextCache->prev = pLRUCacheTbl->cache;
                pPrevCache->next = pLRUCacheTbl->cache;
            }
            return;
        }
        pLRUCacheTblPre = pLRUCacheTbl;
        pLRUCacheTbl = pLRUCacheTbl->next;
    }

    pNewCache = (LRUCache*)malloc(sizeof(LRUCache));
    (void)memset(pNewCache, 0, sizeof(LRUCache));
    pNewCache->key = key;
    pNewCache->value = value;

    pLRUCacheTblNew = (LRUCacheTbl*)malloc(sizeof(LRUCacheTbl));
    (void)memset(pLRUCacheTblNew, 0, sizeof(LRUCacheTbl));

    pLRUCacheTblNew->key = key;
    pLRUCacheTblNew->cache = pNewCache;
    pLRUCacheTblPre->next = pLRUCacheTblNew;

    pPrevCache = g_LRUCacheHead;
    pNextCache = g_LRUCacheHead->next;
    pNewCache->next = pNextCache;
    pNewCache->prev = pPrevCache;
    pNextCache->prev = pNewCache;
    pPrevCache->next = pNewCache;
    g_LRUCacheCnt++;

    if (g_LRUCacheCnt > g_LRUCacheNum)
    {
        pDelCache = g_LRUCacheTail->prev;
        hash_key = HASH(pDelCache->key);
        pLRUCacheTbl = g_LRUCacheHashHead[hash_key].next;
        pLRUCacheTblPre = &g_LRUCacheHashHead[hash_key];
        while (pLRUCacheTbl != NULL)
        {
            if (pLRUCacheTbl->cache == pDelCache)
            {
                pLRUCacheTblPre->next = pLRUCacheTbl->next;
                free(pLRUCacheTbl);
                break;
            }
            pLRUCacheTblPre = pLRUCacheTbl;
            pLRUCacheTbl = pLRUCacheTbl->next;
        }

        pPrevCache = g_LRUCacheTail->prev->prev;
        pNextCache = g_LRUCacheTail->next;
        free(g_LRUCacheTail->prev);
        pPrevCache->next = g_LRUCacheTail;
        g_LRUCacheTail->prev = pPrevCache;
        g_LRUCacheCnt--;
    }
    return;
}

void lRUCacheFree(LRUCache* obj) {
    int i = 0;
    LRUCache* pLRUCache = g_LRUCacheHead;
    LRUCacheTbl* pLRUCacheTbl0 = NULL;
    LRUCacheTbl* pLRUCacheTbl1 = NULL;
    while (pLRUCache != NULL)
    {
        pLRUCache = pLRUCache->next;
        if (pLRUCache)
            free(pLRUCache->prev);
    }
    free(g_LRUCacheTail);
    g_LRUCacheHead = NULL;
    g_LRUCacheTail = NULL;
    for (i = 0; i < HASH_NUM; i++)
    {
        pLRUCacheTbl0 = g_LRUCacheHashHead[i].next;
        pLRUCacheTbl1 = g_LRUCacheHashHead[i].next;
        while (pLRUCacheTbl0 != NULL)
        {
            pLRUCacheTbl1 = pLRUCacheTbl0->next;
            free(pLRUCacheTbl0);
            pLRUCacheTbl0 = pLRUCacheTbl1;
        }
    }
    free(g_LRUCacheHashHead);
    g_LRUCacheHashHead = NULL;
    return;
}

/**
* Your LRUCache struct will be instantiated and called as such:
* LRUCache* obj = lRUCacheCreate(capacity);
* int param_1 = lRUCacheGet(obj, key);

* lRUCachePut(obj, key, value);

* lRUCacheFree(obj);
*/
```