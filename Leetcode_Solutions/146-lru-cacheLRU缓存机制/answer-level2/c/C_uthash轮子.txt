### 解题思路
借uthash轮子，撸不动hash，太♂了。

主要思路是双向链表进行置换成最新操作，然后查询操作由hash表来实现。因此它们均摊为O(1)
+ hash表存双向链表节点的地址，以key值为键，值为链表节点指针（地址）
+ 双向链表：维护最近使用即优先，最近访问的立马到双向链表之前，索引对于上述通过hash表查询的节点指针，删除它并将其移到表头都是O(1)时间。
最关键的操作就是：删除双向链表节点后插入到表头，以及容量已满，删除hash节点（一定要删除不然重复）和释放链表结点。

不管什么，每次要free就会拖慢速度，但是正确方式就是要循环free完！

### 代码

```c
typedef struct LinkNode {  // 1.双链表结点
    int key;
    int val;
    struct LinkNode *prev;
    struct LinkNode *next;
} LinkNode, *NodePtr;

typedef struct DoublyLinkedList {  // 2.双向链表
    NodePtr head;
    NodePtr tail;
} DLLNode;

typedef struct HashNode {  // 3.结点hash表
    int key;
    NodePtr node;
    UT_hash_handle hh;
} HashNode, *HashPtr;

typedef struct {  // 4.LRU缓存
    int size;
    int capacity;
    DLLNode *DLL;  // 双向链表
    HashPtr NodeMap;
} LRUCache;

// 1.创建双链表
DLLNode* DLLCreate() {
    DLLNode *node = (DLLNode*)malloc(sizeof(DLLNode));
    node->head = (NodePtr)calloc(1, sizeof(LinkNode));
    node->tail = (NodePtr)calloc(1, sizeof(LinkNode));
    node->head->next = node->tail;  // 首尾自连
    node->tail->prev = node->head;
    return node;
}

// 2.删除结点(指定某个结点而不free)
void DLLRemove(NodePtr node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

// 3.在双链表头部添加结点
void DLLAdd(LRUCache *obj, NodePtr node) {
    obj->DLL->head->next->prev = node;  // 第一个结点前驱指向node
    node->next = obj->DLL->head->next;  // node的后继指向初始第一个
    node->prev = obj->DLL->head;  // node前驱指向head
    obj->DLL->head->next = node;  // head后继指向node
}

// 4.LRU的增量计算，从该节点中删除到双向链表的头部
void lRUCacheIncrease(LRUCache *obj, NodePtr node) {
    DLLRemove(node);
    DLLAdd(obj, node);
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *cache = (LRUCache*)calloc(1, sizeof(LRUCache));
    cache->capacity = capacity;
    return cache;
}

int lRUCacheGet(LRUCache* obj, int key) {
    HashPtr p = NULL;
    HASH_FIND_INT(obj->NodeMap, &key, p);
    if (!p) return -1;
    lRUCacheIncrease(obj, p->node);  // 增加访问次数
    return p->node->val;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if (!obj->capacity) return;  // 不存在!
    // 1.先查找是否在表内
    HashPtr p = NULL;
    HASH_FIND_INT(obj->NodeMap, &key, p);
    if (!p) {
        // (1)判断容量
        if (obj->size == obj->capacity) {
            HASH_FIND_INT(obj->NodeMap, &obj->DLL->tail->prev->key, p);  // 查找双链表最小频率
            // 删除结点（这里需要注意，先得到hash结点指针，他不会free）
            HASH_DEL(obj->NodeMap, p);
            NodePtr tmp = p->node;  // 暂存要释放
            DLLRemove(obj->DLL->tail->prev);  // 删除最后一个未使用的
            free(tmp);  // 释放结点
            obj->size--;  // 个数减一
        }
        // (2)新建链表结点与hash结点
        NodePtr newNode = (NodePtr)calloc(1, sizeof(LinkNode));
        newNode->val = value;
        newNode->key = key;
        p = (HashPtr)malloc(sizeof(HashNode));  // 创建hash节点
        p->key = key;
        p->node = newNode;  // value为指针（地址）
        HASH_ADD_INT(obj->NodeMap, key, p);  // 加入节点值
        obj->size++;  // 个数增加1
        // (3)新建双向链表
        if (!obj->DLL) obj->DLL = DLLCreate();
        DLLAdd(obj, newNode);  // 加入双向链表表头
    } else {
        p->node->val = value;  // 更新
        lRUCacheIncrease(obj, p->node);  // 增加一次访问次数
    }
}

void lRUCacheFree(LRUCache* obj) {
    // 1.删除hash表
    HashPtr q, p;
    HASH_ITER(hh, obj->NodeMap, p, q) {
        HASH_DEL(obj->NodeMap, p);
    }
    // 2.删除双向链表
    while (obj->DLL && obj->DLL->head) {  // 只有一个get还没创建双向链表
        obj->DLL->tail = obj->DLL->head->next;
        free(obj->DLL->head);
        obj->DLL->head = obj->DLL->tail;
    }
    free(obj);
}
```