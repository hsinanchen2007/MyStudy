### 解题思路
    用C容量过小时用哈希桶会超时，所以把容量设置的很大。
    加载因子没有用上的原因是没有写resize函数，C + 哈希桶时间压的太紧，所以没有扩展写，表的容量太小随之带来的是桶的深度过深会导致插入及查找耗时过长而超时。
    hash右移异或的原因是想尽可能多的用上数的位信息。

### 代码

```c
#define DEFAULTTABLESIZE 1000001
#define DEFAULTLOADFACTOR 0.7

typedef struct entry {
    int key;
    struct entry* next;
} entry;

typedef struct HashSet {
    int cap;
    float loadfactor;
    int size;
    entry** table;
} MyHashSet;

/** Initialize your data structure here. */

int HashCode(MyHashSet* set, int key)
{
    int hash = 0;
    hash = key & 0xffff;
    hash ^= key >> 16;
    return key % set->cap;
}

MyHashSet* myHashSetCreate() {
    MyHashSet* s = (MyHashSet*)malloc(sizeof(MyHashSet));
    s->cap = DEFAULTTABLESIZE;
    s->loadfactor =  DEFAULTLOADFACTOR;
    s->table = (entry**)malloc(sizeof(entry*) * s->cap);
    memset(s->table, NULL, sizeof(entry*) * s->cap);
    return s;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int hash = HashCode(obj, key);
    obj->size++;
    if (!obj->table[hash]) {
        entry* e = (entry*)malloc(sizeof(entry));
        e->next = NULL;
        e->key = key;
        obj->table[hash] = e;
    } else {
        entry* p = obj->table[hash];
        while (p->next) {
            if (p->key == key) {
                return;
            }
            p = p->next;
        }
        if (p->key == key) {
            return;
        }
        entry* e = (entry*)malloc(sizeof(entry));
        e->next = NULL;
        e->key = key;
        p->next = e;
    }
    return;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int hash = HashCode(obj, key);
    entry* p = obj->table[hash];
    if (p) {
        if (p->key == key) {
            entry* pFree = p;
            obj->table[hash] = p->next;
            free(pFree);
            return;
        }
        while (p->next) {
            if (p->next->key == key) {
                entry* pFree = p->next;
                p->next = p->next->next;
                free(pFree);
                return;
            }
        }
    }
    return;
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    int hash = HashCode(obj, key);
    entry* p = obj->table[hash];
    if (!p) {
        return false;
    } else {
        while (p) {
            if (p->key == key) {
                return true;
            }
            p = p->next;
        }
    }
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    for (int i = 0; i < obj->cap; i++) {
        entry* p = obj->table[i];
        while (p) {
            entry* pFree = p;
            p = p->next;
            free(pFree);
        }
    }
    free(obj);
    return;
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/
```