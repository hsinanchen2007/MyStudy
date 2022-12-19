### 解题思路
使用uthash 做哈希表 （实际上用两个数组也是可以的，但是需要分配的内存会比较大）

#### 需要注意的细节

1. 每次get一个元素,需要将该元素放到双向链表的最后，但是如果操作的元素刚好是最后一个，会导致链表为空，这里的处理是如果元素刚好在链表的最后，则不再操作。

#### 总结下uthash 的常用操作

1. 定义结构体形式如下：
    ```C
    struct UHASH {
        int key;                    /* key */
        struct Node* addr;
        UT_hash_handle hh;         /* makes this structure hashable */
    };
    ```
2. 查找元素
    ```C
    struct UHASH *s = NULL;
    HASH_FIND_INT(obj->hash, &key, s); // 在obj->hash 里面，查找key为 key的元素。
    if(s == NULL) {
        return -1;
    }
    ```
3. 添加元素
    ```C
    struct UHASH *s = (struct UHASH *)malloc(sizeof(struct UHASH));
    s->key = key;
    s->addr = obj->last;
    HASH_ADD_INT(obj->hash, key, s);
    ```
4. 删除元素
    ```C
    void delete_user(struct my_struct *user) {
        HASH_DEL(users, user);  /* user: pointer to deletee */
        free(user);             /* optional; it's up to you! */
    }
    ```
### 代码

```c
struct Node {
    struct Node *next;
    struct Node *pre;
    int key;
    int val;
};

struct UHASH {
    int key;                    /* key */
    struct Node* addr;
    UT_hash_handle hh;         /* makes this structure hashable */
};

typedef struct {
    struct Node *head;
    struct Node *last;
    int cap;
    int size;
    struct UHASH *hash; 
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = (LRUCache *)malloc(sizeof(LRUCache));
    obj->size = 0;
    obj->cap = capacity;
    obj->head = (struct Node *)malloc(sizeof(struct Node));
    obj->head->next = NULL;
    obj->last = obj->head;
    obj->hash = NULL;
    return obj;
}


void moveToLast(LRUCache *obj, struct Node *p) {
    if (p == obj->last) { /* 如果 p 已经是最后一个元素，则不需要放到最后 */
        return;
    }
    p->pre->next = p->next;
    if (p->next != NULL) {
        p->next->pre = p->pre;
    }
    obj->last->next = p;
    p->pre = obj->last;
    obj->last = obj->last->next;
    obj->last->next = NULL;
    return;
}

void lRUAddItem(LRUCache *obj, int key, int value) {
    // add node
    obj->last->next = (struct Node *)malloc(sizeof(struct Node));
    obj->last->next->key = key;
    obj->last->next->val = value;
    obj->last->next->next = NULL;
    obj->last->next->pre = obj->last;
    obj->last = obj->last->next;

    // add hash
    struct UHASH *s = (struct UHASH *)malloc(sizeof(struct UHASH));
    s->key = key;
    s->addr = obj->last;
    HASH_ADD_INT(obj->hash, key, s);

    return;
}

void lRURemoveFirst(LRUCache *obj) {
    // remove node
    struct Node *tmp = obj->head->next;
    obj->head->next = tmp->next;
    if (tmp->next != NULL) {
        tmp->next->pre = obj->head;
    }
    tmp->next = NULL;
    tmp->pre = NULL;

    //remove hash
    struct UHASH *st = NULL;
    HASH_FIND_INT(obj->hash, &(tmp->key), st);
    HASH_DEL(obj->hash, st);
    free(tmp);
    free(st);
    return;
}

int lRUCacheGet(LRUCache* obj, int key) {
    struct UHASH *s = NULL;
    HASH_FIND_INT(obj->hash, &key, s);
    if(s == NULL) {
        return -1;
    }
    moveToLast(obj, s->addr);
    return obj->last->val;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    struct UHASH *s = NULL;
    HASH_FIND_INT(obj->hash, &key, s);
    if(s != NULL) {
        s->addr->val = value;
        moveToLast(obj, s->addr);
        return;
    }
    lRUAddItem(obj, key, value);

    if (obj->size == obj->cap) {
        lRURemoveFirst(obj);
        return;
    }
    obj->size++;
    return;
}

void lRUCacheFree(LRUCache* obj) {
    struct Node *p = obj->head;
    struct Node *t = NULL;
    while (p->next != NULL) {
        t = p->next;
        p->next = t->next;
        free(t);
    }
    struct UHASH *current_user, *tmp;
    HASH_ITER(hh, obj->hash, current_user, tmp) {
        HASH_DEL(obj->hash,current_user);  /* delete; users advances to next */
        free(current_user);            /* optional- if you want to free  */
    }
    free(obj);
    return;
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
```