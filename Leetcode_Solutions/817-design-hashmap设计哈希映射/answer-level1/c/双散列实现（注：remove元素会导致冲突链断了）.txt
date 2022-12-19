## 方法一
`开放地址法`需要注意，`get`元素需要遍历所有冲突情况（效率会低），因为`remove`元素，可能导致后续`get`元素的冲突链断了。
```
#define HASH_SIZE 10007
#define INF 0x7fffffff

typedef struct HashNode_t {
    int key;
    int value;
} HashNode;

typedef struct {
    HashNode arr[HASH_SIZE];
} MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
    MyHashMap* hashMap = (MyHashMap*)malloc(sizeof(MyHashMap));
    memset(hashMap, -1, sizeof(MyHashMap));
    return hashMap;
}

inline int Hash1(int key)
{
    return key % HASH_SIZE;
}

inline int Hash2(int key)
{
    return 1 + (key % (HASH_SIZE - 1));
}


/** value will always be non-negative. */
inline void myHashMapPut(MyHashMap* obj, int key, int value) {
    int hash1 = Hash1(key);
    int hash2 = Hash2(key);
    int hashX;
    for (int i = 0; ; ++i) {
        hashX = (hash1 + i * hash2 % HASH_SIZE) % HASH_SIZE;
        if (obj->arr[hashX].key == -1) {
            obj->arr[hashX].key = key;
            obj->arr[hashX].value = value;
            return ;
        } else if (obj->arr[hashX].key == key) {
            obj->arr[hashX].value = value;
            return ;
        }
    }
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
inline int myHashMapGet(MyHashMap* obj, int key) {
    int hash1 = Hash1(key);
    int hash2 = Hash2(key);
    int hashX;
    for (int i = 0; i < HASH_SIZE; ++i) {
        /* 因为remove操作可能使冲突链断了，所以要遍历所有冲突情况 */
        hashX = (hash1 + i * hash2 % HASH_SIZE) % HASH_SIZE;
        if (obj->arr[hashX].key == key) {
            return obj->arr[hashX].value;
        }
    }
    return -1;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
inline void myHashMapRemove(MyHashMap* obj, int key) {
    int hash1 = Hash1(key);
    int hash2 = Hash2(key);
    int hashX;
    for (int i = 0; ; ++i) {
        hashX = (hash1 + i * hash2 % HASH_SIZE) % HASH_SIZE;
        if (obj->arr[hashX].key == -1) {
            return ;
        } else if (obj->arr[hashX].key == key) {
            obj->arr[hashX].key = -1;
            return ;
        }
    }
}

inline void myHashMapFree(MyHashMap* obj) {
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/
```


## 方法二 把Hash数组开大(提升效率)
开大数组，减少冲突，没有冲突链，`remove`元素就不会造成影响。
```c
#define HASH_SIZE 100003
#define INF 0x7fffffff

typedef struct HashNode_t {
    int key;
    int value;
} HashNode;

typedef struct {
    HashNode arr[HASH_SIZE];
} MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
    MyHashMap* hashMap = (MyHashMap*)malloc(sizeof(MyHashMap));
    memset(hashMap, -1, sizeof(MyHashMap));
    return hashMap;
}

inline int Hash1(int key)
{
    return key % HASH_SIZE;
}

inline int Hash2(int key)
{
    return 1 + (key % (HASH_SIZE - 1));
}


/** value will always be non-negative. */
inline void myHashMapPut(MyHashMap* obj, int key, int value) {
    int hash1 = Hash1(key);
    int hash2 = Hash2(key);
    int hashX;
    for (int i = 0; ; ++i) {
        hashX = (hash1 + i * hash2 % HASH_SIZE) % HASH_SIZE;
        if (obj->arr[hashX].key == -1) {
            obj->arr[hashX].key = key;
            obj->arr[hashX].value = value;
            return ;
        } else if (obj->arr[hashX].key == key) {
            obj->arr[hashX].value = value;
            return ;
        }
    }
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
inline int myHashMapGet(MyHashMap* obj, int key) {
    int hash1 = Hash1(key);
    int hash2 = Hash2(key);
    int hashX;
    for (int i = 0; ; ++i) {
        hashX = (hash1 + i * hash2 % HASH_SIZE) % HASH_SIZE;
        if (obj->arr[hashX].key == -1) {
            return -1;
        } else if (obj->arr[hashX].key == key) {
            return obj->arr[hashX].value;
        }
    }
    return -1;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
inline void myHashMapRemove(MyHashMap* obj, int key) {
    int hash1 = Hash1(key);
    int hash2 = Hash2(key);
    int hashX;
    for (int i = 0; ; ++i) {
        hashX = (hash1 + i * hash2 % HASH_SIZE) % HASH_SIZE;
        if (obj->arr[hashX].key == -1) {
            return ;
        } else if (obj->arr[hashX].key == key) {
            obj->arr[hashX].key = -1;
            return ;
        }
    }
}

inline void myHashMapFree(MyHashMap* obj) {
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/
```