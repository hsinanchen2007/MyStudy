![image.png](https://pic.leetcode-cn.com/891dc4f010099352714358dcfd4d8edda378e621bd7679545e3b5aa9209e008e-image.png)


```
// 单链表操作
typedef struct node {
    int key;
    int val;
    struct node* next;
} NODE;

NODE* AddNode(NODE* obj, int key, int val);
NODE* DelNode(NODE* obj, int key);
NODE* FindNode(NODE* obj, int key);

// 前插法：插入到链表的前端
NODE* AddNode(NODE* obj, int key, int val)
{
    if (FindNode(obj, key) == true) {
        return obj;
    }
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->key = key;
    node->val = val;
    node->next = obj;
    return node;
}

NODE* DelNode(NODE* obj, int key)
{
    NODE* head = NULL;
    if (obj == NULL) {
        return obj;
    }
    if (obj->key == key) {
        head = obj->next;
        free(obj);
        return head;
    }
    NODE* prev = obj;
    NODE* node = obj->next;
    while (node) {
        if (node->key == key) {
            prev->next = node->next;
            free(node);
            return obj;
        }
        prev = node;
        node = node->next;
    }
    return obj;
}

NODE* FindNode(NODE* obj, int key)
{
    NODE* node = obj;
    while (node) {
        if (node->key == key) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}


#define HASH_SIZE   1000
int hash_fun(int x)
{
    return x % HASH_SIZE;
}

typedef int(*HASH_FUN)(int);
typedef struct {
    HASH_FUN fun;
    int len;
    NODE* bkt[0];
} MyHashMap;

MyHashMap* myHashMapCreate();
void myHashMapPut(MyHashMap* obj, int key, int value);
int myHashMapGet(MyHashMap* obj, int key);
void myHashMapRemove(MyHashMap* obj, int key);
void myHashMapFree(MyHashMap* obj);

/** Initialize your data structure here. */
MyHashMap* myHashMapCreate()
{
    MyHashMap* obj = NULL;
    obj = (MyHashMap*)malloc(sizeof(MyHashMap) + HASH_SIZE * sizeof(NODE*));
    if (obj == NULL) {
        return NULL;
    }
    memset(obj, 0, sizeof(MyHashMap) + HASH_SIZE * sizeof(NODE*));
    obj->fun = hash_fun;
    obj->len = HASH_SIZE;
    return obj;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value)
{
    unsigned int idx = obj->fun(key);
    NODE* head = obj->bkt[idx];
    NODE* fobj = FindNode(head, key);
    if (fobj) {
        fobj->val = value;
        return;
    }
    head = AddNode(head, key, value);
    obj->bkt[idx] = head;
    return;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
#define NOT_EXIST (-1)
int myHashMapGet(MyHashMap* obj, int key)
{
    unsigned int idx = obj->fun(key);
    NODE* head = obj->bkt[idx];
    NODE* fobj = FindNode(head, key);
    if (fobj) {
        return fobj->val;
    }
    return NOT_EXIST;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key)
{
    unsigned int idx = obj->fun(key);
    NODE* head = obj->bkt[idx];
    head = DelNode(head, key);
    obj->bkt[idx] = head;
    return;
}

void myHashMapFree(MyHashMap* obj)
{
    for (int i = 0; i < obj->len; i++) {
        NODE* head = obj->bkt[i];
        if (head == NULL) {
            continue;
        }
        NODE* node = head;
        NODE* next = head->next;
        while (node) {
            next = node->next;
            free(node);
            node = next;
        }
        obj->bkt[i] = NULL;
    }
    free(obj);
    return;
}
```
/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/