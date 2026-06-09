![08F2CAD1-02B4-466F-BB49-0194965C3B71.jpeg](https://pic.leetcode-cn.com/da186131fbd0ee3afeaf3e003ca0a522d1ee21c2ca8de1456bdc7a860575c290-08F2CAD1-02B4-466F-BB49-0194965C3B71.jpeg)

```
#define MAXSIZE 1000000


typedef struct {
    int val[MAXSIZE];
    int num;
} TwoSum;

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashNode;

HashNode *g_this = NULL;
/** Initialize your data structure here. */

TwoSum* twoSumCreate() {
    TwoSum *twoSum = (TwoSum *)malloc(sizeof(TwoSum));
    return twoSum;
}

/** Add the number to an internal data structure.. */
void twoSumAdd(TwoSum* obj, int number) {
    HashNode *tmpHashNode;
    int key = number;
    HASH_FIND_INT(g_this, &key, tmpHashNode);
    if (tmpHashNode == NULL) {
        tmpHashNode = (HashNode *)malloc(sizeof(HashNode));
        tmpHashNode->key = key;
        tmpHashNode->val = 0;
        tmpHashNode->val = 1;
        HASH_ADD_INT(g_this, key, tmpHashNode);
    } else {
        tmpHashNode->val++; 
    }
    //printf("add: key: %d, val: %d\n", tmpHashNode->key, tmpHashNode->val);
}

/** Find if there exists any pair of numbers which sum is equal to the value. */
bool twoSumFind(TwoSum* obj, int value) {
    HashNode *current;
    HashNode *tmp;
    HashNode *tmpHashNode;
    int key;
    //printf("find-in: val: %d\n", value);
    HASH_ITER(hh, g_this, current, tmp) {
        //printf("find: key: %d, val: %d\n", current->key, current->val);
        current->val--;
        key = value - current->key;
        //printf("find: key: %d\n", key);
        HASH_FIND_INT(g_this, &key, tmpHashNode);
        if ((tmpHashNode != NULL) && (tmpHashNode->val != 0)) {
            current->val++;
            return true;
        }
       current->val++;
    }
    return false;
}

void twoSumFree(TwoSum* obj) {
    HashNode *current;
    HashNode *tmp;
    HASH_ITER(hh, g_this, current, tmp) {
        HASH_DEL(g_this, current);
        free(current);
    }
    free(obj);
}

/**
 * Your TwoSum struct will be instantiated and called as such:
 * TwoSum* obj = twoSumCreate();
 * twoSumAdd(obj, number);
 
 * bool param_2 = twoSumFind(obj, value);
 
 * twoSumFree(obj);
*/
```
