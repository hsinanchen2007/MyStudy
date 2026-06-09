先贴运行结果吧！！！
![运行结果](https://pic.leetcode-cn.com/93595456af03019857bf657d968b2a030f68bbc95ee34d45d639dd1ba8b24764-image.png)

说明：
    * 采用 hash 表 + 双向循环链表；
    * 采用 双向循环链表是为了方便将某个节点移动到表头，以及获取表尾节点
    * hash表采用拉链法，简单的 key % capacity，故时间复杂度只能说接近于O(1)

思路：
    * 双链表节点存储 key, value, next, prev 信息，没啥好说的
    * hash 表采用拉链法，哈希函数使用 key % capacity, 节点存储双链表中key对应节点的地址和next
    * 创建链表时首先分别分配 capacity 个双向循环链接节点和hash节点，避免后续再分配(但是相应的增加了复杂度，原本是想着可以增加加快运行速度的，从运行结果看来，貌似并不理想)
    * get 操作直接查找hash表，找到了就返回对应的双链表节点中value，找不到就返回-1
    * put 操作先判断是否存在 key 对应的节点，找到了就直接替换为新的 value; 否则讲新链表中的最后一个节点替换为新的 key 和 value
```
#define HASH_BUCKET(obj, key) (&obj->hash[key % obj->capacity])

struct double_link_list
{
    int key;
    int val;
    struct double_link_list *prev;
    struct double_link_list *next;
};

struct link_list
{
    struct double_link_list *node;
    struct link_list *next;
};

typedef struct 
{
    int capacity;
    struct link_list *hash;
    struct double_link_list *head;
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *obj = (LRUCache *) calloc(1, sizeof(LRUCache));
    obj->hash = (struct link_list *) calloc(capacity, sizeof(struct link_list));
    obj->head = (struct double_link_list *) calloc(1, sizeof(struct double_link_list));
    obj->head->next = obj->head->prev = obj->head;
    obj->capacity = capacity;

    // 预分配好链表空间 && 预分配hash空间
    for (int i = 0; i < capacity; ++i) {
        struct double_link_list *dnode = (struct double_link_list *) calloc(1, sizeof(struct double_link_list));
        dnode->next = obj->head->next;
        dnode->prev = obj->head;
        dnode->next->prev = dnode;
        obj->head->next = dnode;

        struct link_list *node = (struct link_list *) calloc(1, sizeof(struct link_list));
        node->next = obj->hash[0].next;
        obj->hash[0].next = node;
    }

    return obj;
}

// 返回 hash 表中 key 对应的节点的上一个节点。
static struct link_list *
hash_find_key(LRUCache *obj, int key)
{
    struct link_list *p = HASH_BUCKET(obj, key);

    while (p->next && p->next->node && p->next->node->key != key) {
        p = p->next;
    }

    return p;
}

static void double_list_move_to_head(LRUCache *obj,
                struct double_link_list *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;

    node->next = obj->head->next;
    obj->head->next->prev = node;
    node->prev = obj->head;
    obj->head->next = node;
}

int lRUCacheGet(LRUCache* obj, int key) {
    struct link_list *p = hash_find_key(obj, key)->next;
    if (!p || !p->node) {
        return -1;
    }

    double_list_move_to_head(obj, p->node);
    return p->node->val;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    // 先查找 hash 表中是否有 key 节点存在，
    // 防止 key 相同，value不相同的插入
    struct link_list *p = hash_find_key(obj, key);
    if (!p->next) {
        // 没找到的话就找双链表中最后的一个节点
        p = hash_find_key(obj, obj->head->prev->key);
    }
    struct link_list *node = p->next;
    struct link_list *new = HASH_BUCKET(obj, key);
    
    // 先断开旧的hash桶
    p->next = node->next;
    // 再链接上新的hash桶
    node->next = new->next;
    new->next = node;
    
    // 修改尾结点的值为新值，同时将尾结点移动到头结点
    if (!node->node) {
        node->node = obj->head->prev;
    }
    node->node->key = key;
    node->node->val = value;
    double_list_move_to_head(obj, node->node);
}

void lRUCacheFree(LRUCache* obj) {
    for (int i = 0; i < obj->capacity; ++i) {
        struct link_list *p = obj->hash[i].next;
        while (p) {
            struct link_list *temp = p;
            p = p->next;
            free(temp);
            temp = NULL;
        }
    }
    free(obj->hash);
    obj->hash = NULL;

    struct double_link_list *dp = obj->head->next;
    while (dp != obj->head) {
        struct double_link_list *temp = dp;
        dp = dp->next;
        free(temp);
        temp = NULL;
    }
    dp = NULL;
    free(obj->head);
    obj->head = NULL;
    
    free(obj);
    obj = NULL;
}
```
