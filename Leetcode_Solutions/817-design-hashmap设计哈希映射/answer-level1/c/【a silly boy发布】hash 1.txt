```
#define MAXSIZE 1000001

typedef struct {
    int key[MAXSIZE];
    bool flag[MAXSIZE];
} MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
    MyHashMap *hashMap = (MyHashMap *)malloc(sizeof(MyHashMap));
    memset(hashMap->key, 0, MAXSIZE * sizeof(int));
    memset(hashMap->flag, 0, MAXSIZE * sizeof(bool));
    return hashMap;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
    obj->key[key] = value;
    obj->flag[key] = true;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
    if (obj->flag[key] == false) {
        return -1;
    } else {
        return obj->key[key];
    }
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
    obj->flag[key] = false;
}

void myHashMapFree(MyHashMap* obj) {
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
