### 解题思路
HASHSIZE 1000效率最高
myHashMapRemove出现了删除时的错误，需要记住！

### 代码

```c
#define HASHSIZE 1000
typedef struct node {
    int key;
    int val;
    struct node* next;
} Node;

typedef struct {
    Node* arr[0];
} MyHashMap;
Node* FindNode(Node* idxHead, int key)
{
    if (idxHead == NULL) {
        return NULL;
    }
    while (idxHead != NULL) {
        if (idxHead->key == key) {
            return idxHead;
        }
        idxHead = idxHead->next;
    }
    return NULL;
}
/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
    MyHashMap* hashMap = (MyHashMap*)calloc(1, sizeof(MyHashMap) + HASHSIZE * sizeof(Node*));
    return hashMap;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
    unsigned int idx = key % HASHSIZE;
    Node* idxHead = obj->arr[idx];
    Node* node = FindNode(idxHead, key);
    if (node == NULL) { // 没找到就插入
        Node* newNodeHead = (Node*)malloc(sizeof(Node));
        newNodeHead->key = key;
        newNodeHead->val = value;
        newNodeHead->next = idxHead;
        obj->arr[idx] = newNodeHead;
    } else {
        node->val = value;
    }
    return;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
    unsigned int idx = key % HASHSIZE;
    Node* idxHead = obj->arr[idx];
    Node* node = FindNode(idxHead, key);
    if (node) {
        return node->val;
    }
    return -1;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
    unsigned int idx = key % HASHSIZE;
    Node* idxHead = obj->arr[idx];
    Node* preNode;
    if (idxHead == NULL) {
        return;
    }
    if (idxHead->key == key) {
        obj->arr[idx] = idxHead->next;
        free(idxHead);
        return;
    }
    preNode = idxHead;
    idxHead = idxHead->next;
    while (idxHead != NULL) {       
        if (idxHead->key == key) {
            preNode->next = idxHead->next;
            free(idxHead);
            return;
        }
        preNode = idxHead;
        idxHead = idxHead->next;
    }
}

void myHashMapFree(MyHashMap* obj) {
    Node* nodeTemp;
    for (int i = 0; i < HASHSIZE; i++) {
        Node* nodeHead = obj->arr[i];
        if (nodeHead == NULL) {
            continue;
        }
        while (nodeHead) {
            nodeTemp = nodeHead;
            nodeHead = nodeHead->next;
            free(nodeTemp);
        }
        obj->arr[i] = NULL;
    }
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