![0364BF95-A547-4921-AE37-D05EE02CCBAB.jpeg](https://pic.leetcode-cn.com/fdd21b11e77495331c0a03c3ab8d6f1bef393836d3a98b8308edbd9a6deeaf5c-0364BF95-A547-4921-AE37-D05EE02CCBAB.jpeg)

```

#define MAXSIZE 1000001

typedef struct {
    int key[MAXSIZE];
} MyHashSet;

/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
    MyHashSet *tmpHashNode = (MyHashSet *)malloc(sizeof(MyHashSet));
    memset(tmpHashNode, 0, sizeof(MyHashSet));
    return tmpHashNode;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    if (obj->key[key] != 1) {
        obj->key[key] = 1;
    }
}

void myHashSetRemove(MyHashSet* obj, int key) {
    if (obj->key[key] == 1) {
        obj->key[key] = 0;
    }
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    if (obj->key[key] == 1) {
        return true;
    } else {
        return false;
    }
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
