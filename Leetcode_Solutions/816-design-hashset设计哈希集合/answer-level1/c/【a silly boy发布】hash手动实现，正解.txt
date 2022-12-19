![254B90C3-9DEA-4BF1-9F4C-53FF88D20EC4.jpeg](https://pic.leetcode-cn.com/a57816049fe2d3730f7ea0374e8601f7f341f3a73936f183c52521028f41634e-254B90C3-9DEA-4BF1-9F4C-53FF88D20EC4.jpeg)

```
typedef struct Val {
    int val;
    struct Val *next;
} Val;

typedef struct {
    int key;
    int valNum;
    Val *val;
} MyHashSet;

/** Initialize your data structure here. */
#define STRUCTSIZE 1000

MyHashSet* myHashSetCreate() {
    MyHashSet *hashEntry = (MyHashSet*)malloc(STRUCTSIZE * sizeof(MyHashSet));
    int i;
    for (i = 0; i < STRUCTSIZE; i++) {
        hashEntry[i].key = i;
        hashEntry[i].valNum = 0;
        hashEntry[i].val = NULL;
    }

    return hashEntry;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int val = key;
    int keyAfter = key % STRUCTSIZE;

    MyHashSet *tmpHashEntry;
    tmpHashEntry = &obj[keyAfter];
    if (tmpHashEntry->valNum == 0) {
        tmpHashEntry->val = (Val *)malloc(sizeof(Val));
        tmpHashEntry->val->val = val;
        tmpHashEntry->val->next = NULL;
        tmpHashEntry->valNum++;
    } else {
        Val *tmpVal = tmpHashEntry->val;
        while (tmpVal->next != NULL) {
            if (tmpVal->val == val) {
                goto __END__;
            } else {
                tmpVal = tmpVal->next;
            }
        }
        if (tmpVal->val == val) {
            goto __END__;
        }
        tmpVal->next = (Val *)malloc(sizeof(Val));
        tmpVal = tmpVal->next;
        tmpVal->val = val;
        tmpVal->next = NULL;
        tmpHashEntry->valNum++;
    }
__END__:
    //printf("add: key: %d, val: %d, keynum: %d\n", keyAfter, val, tmpHashEntry->valNum);
    return;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int val = key;
    int keyAfter = key % STRUCTSIZE;
    MyHashSet *tmpHashEntry;
    tmpHashEntry = &obj[keyAfter];
    Val *tmpVal;
    Val *oldTmpVal = NULL;
    Val *tttt = NULL;
    int i;

    if (tmpHashEntry->valNum == 0) {
        goto __END__;
    } else {
        tmpVal = tmpHashEntry->val;
        oldTmpVal = tmpHashEntry->val;
        while (tmpVal != NULL) {
            //printf("tmpVal->val: %d, val: %d\n", tmpVal->val, val);
            if (tmpVal->val == val) {
                if (oldTmpVal == tmpVal) {
                    tmpVal = tmpVal->next;
                    tmpHashEntry->val = tmpVal;
                    free(oldTmpVal);
                } else {
                    oldTmpVal->next = tmpVal->next;
                    free(tmpVal);
                }
                tmpHashEntry->valNum--;
                goto __END__;
            } else {
                oldTmpVal = tmpVal;
            }
            tmpVal = tmpVal->next;
        }
    }
__END__:
    //printf("remove: key: %d, val: %d, keynum: %d\n", keyAfter, val, tmpHashEntry->valNum);
    return;
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    int val = key;
    int keyAfter = key % STRUCTSIZE;
    MyHashSet *tmpHashEntry;
    tmpHashEntry = &obj[keyAfter];
    Val *tmpVal = tmpHashEntry->val;
    if (tmpHashEntry->valNum == 0) {
        return false;
    }
    while (tmpVal != NULL) {
        if (tmpVal->val == val) {
            return true;
        }
        tmpVal = tmpVal->next;
    }
    return false;
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
