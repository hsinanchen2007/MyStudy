### 解题思路
开放定址法的线性探测

### 代码

```c
#define HASHSIZE 10001

typedef struct {
    int *elem;
    int count;
} MyHashSet;

/** Initialize your data structure here. */
bool myHashSetContains(MyHashSet* obj, int key);

MyHashSet* myHashSetCreate() {
    MyHashSet* obj = malloc(sizeof(MyHashSet));
    obj->count = HASHSIZE;
    obj->elem = (int *)malloc(sizeof(int) * HASHSIZE);
    for(int i=0; i<HASHSIZE; i++)
        obj->elem[i] = -1;
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    if( ! myHashSetContains(obj, key) ){
        int addr = key % HASHSIZE;
        while(obj->elem[addr] != -1)
            addr = (addr + 1) % HASHSIZE;
        obj->elem[addr] = key;
    }
}

void myHashSetRemove(MyHashSet* obj, int key) {
    if( myHashSetContains(obj, key) ){
        int addr = key % HASHSIZE;
        while(obj->elem[addr] != key)
            addr = (addr + 1) % HASHSIZE;
        obj->elem[addr] = -1;
        //printf("obj->elem[%d] = %d\n", addr, obj->elem[addr]);
    }
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    int addr = key % HASHSIZE;
    while(obj->elem[addr] != key){
        addr = (addr + 1) % HASHSIZE;
        if( obj->elem[addr] == -1 || addr == key % HASHSIZE )
            return false;
    }
    return true;
}

void myHashSetFree(MyHashSet* obj) {
    free(obj);
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