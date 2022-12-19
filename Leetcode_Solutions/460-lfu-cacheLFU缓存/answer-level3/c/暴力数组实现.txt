### 解题思路
1、用数组模拟LFU队列，成员除了kv，频率外，增加一个全局递增索引，类似时间戳，用于判定平局时的最近
2、get简单，就是暴力遍历数组
3、put稍微复杂，要处理key已存在时的更新操作，和满时的淘汰操作。

### 代码

```c
typedef struct {
    int key;
    int val;
    int f;
    int idx;
} LFUCache;

int g_len = 0;
int g_cnt = 0;
int g_used = 0;

LFUCache* lFUCacheCreate(int capacity) {
    LFUCache* cache = NULL;

    if (capacity <= 0) {
        g_len = 0;
        return NULL;
    }
    cache = (LFUCache*)malloc(sizeof(LFUCache) * capacity);
    if (cache == NULL) {
        g_len = 0;
    } else {
        g_len = capacity;
    }
    return cache;
}

int lFUCacheGet(LFUCache* obj, int key) {
    for (int i = 0; i < g_used; i++) {
        if (obj[i].key == key) {
            obj[i].f++;
            obj[i].idx = g_cnt;
            g_cnt++;
            return obj[i].val;
        }
    }
    return -1;
}

int DropOneEntry(LFUCache* obj)
{
    int minF = 0;
    int minCnt = 0;
    int i, minIdx;

    if (g_used <= 1) {
        return 0;
    }
    minF = obj[0].f;
    minCnt = obj[0].idx;
    minIdx = 0;
    for (i = 1; i < g_used; i++) {
        if (obj[i].f < minF) {
            minF = obj[i].f;
            minCnt = obj[i].idx;
            minIdx = i;
        } else if (obj[i].f == minF) {
            if (obj[i].idx < minCnt) {
                minCnt = obj[i].idx;
                minIdx = i;
            }
        }
    }
    return minIdx;
}

void lFUCachePut(LFUCache* obj, int key, int value) {
    int idx;
    if (g_len < 1) {
        return;
    }
    for (int i = 0; i < g_used; i++) {
        if (obj[i].key == key) {
            obj[i].f++;
            obj[i].idx = g_cnt;
            g_cnt++;
            obj[i].val = value;
            return;
        }
    }
    if (g_used >= g_len) {
        idx = DropOneEntry(obj);
    } else {
        idx = g_used;
        g_used++;
    }
    obj[idx].key = key;
    obj[idx].val = value;
    obj[idx].f = 1;
    obj[idx].idx = g_cnt;
    g_cnt++;
    return;
}

void lFUCacheFree(LFUCache* obj) {
    free(obj);
    g_len = 0;
    g_cnt = 0;
    g_used = 0;
    return;
}

/**
 * Your LFUCache struct will be instantiated and called as such:
 * LFUCache* obj = lFUCacheCreate(capacity);
 * int param_1 = lFUCacheGet(obj, key);
 
 * lFUCachePut(obj, key, value);
 
 * lFUCacheFree(obj);
*/
```