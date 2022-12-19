### 解题思路
经典的双链表与hash结合的设计问题，这里给出c语言的解法，用到了uthash。

1.构建hash+双向指针的节点

2.查找时，使用hash加速查找，如果找到需要将该节点摘下放到队首

3.写入时，使用hash加速查找

4.如果找到，则将该值更新，并将其摘下放到队首

5.如果未找到，则建立新节点，并加入队首

6.判断容量是否超出，如果超出，则去掉队尾，并从hash表中删除。

注意，在解题过程中，没有对节点进行释放，而是依赖leetcode环境进行释放。


![image.png](https://pic.leetcode-cn.com/49d3c32035346b788a851f4e57c47d721674ffb398b8eb9a2b72382da130f05e-image.png)


### 代码

```c
typedef struct _hash_st {
    int key;
    int val;
    struct _hash_st *pre;
    struct _hash_st *nxt;
    UT_hash_handle hh;
}hash_st;

typedef struct {
    hash_st *head;
    hash_st dlink;
    int capacity;
    int size;
} LRUCache;

//【算法思路】hash+双链表。经典问题，hash加速双链表操作。
// 添加时，如需删除，从链表尾部获得key，从hash和链表同时删除
// 查找时，从hash查找，如果找到，将其放到链表头部
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *obj = (LRUCache *)calloc(1, sizeof(LRUCache));
    obj->capacity = capacity;
    obj->dlink.pre = &obj->dlink;
    obj->dlink.nxt = &obj->dlink;
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    //从hash表中查找
    hash_st *tmph;
    HASH_FIND(hh, obj->head, &key, sizeof(int), tmph);
    if(tmph == NULL) {
        return -1;
    } else {
        int ret = tmph->val;
        //将该节点置顶
        tmph->pre->nxt = tmph->nxt;
        tmph->nxt->pre = tmph->pre;

        tmph->nxt = obj->dlink.nxt;
        tmph->pre = &obj->dlink;
        obj->dlink.nxt->pre = tmph;
        obj->dlink.nxt = tmph;
        return ret;
    }
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    //先检查是否存在
    hash_st *tmph;
    HASH_FIND(hh, obj->head, &key, sizeof(int), tmph);
    if(tmph != NULL) {
        tmph->val = value;

        //将该节点置顶
        tmph->pre->nxt = tmph->nxt;
        tmph->nxt->pre = tmph->pre;

        tmph->nxt = obj->dlink.nxt;
        tmph->pre = &obj->dlink;
        obj->dlink.nxt->pre = tmph;
        obj->dlink.nxt = tmph;
        return;
    }

    hash_st *new = (hash_st *)calloc(1, sizeof(hash_st));
    new->key = key;
    new->val = value;
    new->nxt = obj->dlink.nxt;
    new->pre = &obj->dlink;
    obj->dlink.nxt->pre = new;
    obj->dlink.nxt = new;

    HASH_ADD_KEYPTR(hh, obj->head, &new->key, sizeof(int), new);

    obj->size++;

    //删掉尾部
    if(obj->size > obj->capacity) {
        hash_st *tail = obj->dlink.pre;
        tail->pre->nxt = tail->nxt;
        tail->nxt->pre = tail->pre;

        HASH_DEL(obj->head, tail);

        obj->size--;
    }
}

void lRUCacheFree(LRUCache* obj) {
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
```