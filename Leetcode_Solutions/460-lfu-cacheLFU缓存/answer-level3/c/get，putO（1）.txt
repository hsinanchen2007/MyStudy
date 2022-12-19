### 解题思路
没找到o（1）的答案参考大神的思路花了一下午写了一个
思路就是哈希加双链表
双链表以频率为数组下标  head记录当前次数的较老元素 tail记录当前次数较新元素
fre记录此key值的频率  minf为最小频率
每次get 查找都要更新head、tail和minf


### 代码

```c
#define MAXSIZE  100

struct hashMapNode{
    int key;
    int val;
    int fre;//此key值的频率

    struct hashMapNode* pre;
    struct hashMapNode* next;
    UT_hash_handle hh;
};

typedef struct {
    struct hashMapNode* hashMap;
    struct hashMapNode** head;
    struct hashMapNode** tail;
    int maxL;//最多能存几个key值
    int currL;//当前存了几个key值
    int minf;//记录key值中最小的fre
} LFUCache;


LFUCache* lFUCacheCreate(int capacity) {
    LFUCache* res = malloc(sizeof(LFUCache));
    res->hashMap = NULL;
    res->head = malloc(sizeof(struct hashMapNode*)* MAXSIZE);
    res->tail = malloc(sizeof(struct hashMapNode*)* MAXSIZE);
    for(int i = 0; i < MAXSIZE; i++){
        res->head[i] = NULL;
        res->tail[i] = NULL;
    }
    res->currL = 0;
    res->maxL = capacity;
    res->minf = 0;
    return res;
}

//将node从当前频率的链表中删除
void DEL_node(LFUCache* obj, struct hashMapNode* node){
    int f = node->fre;
    //只有node的情况
    if(!node->pre && !node->next){
        obj->head[f] = NULL;
        obj->tail[f] = NULL;
        return; 
    }
    //node是第一个节点的情况
    if(!node->pre){
        obj->head[f] = node->next;
        node->next->pre = NULL;
        return;
    }
    //node是最后一个节点的情况
    if(!node->next){
        obj->tail[f] = node->pre;
        node->pre->next = NULL;
        return;
    }
    //node前驱后继都存在的情况
    node->pre->next = node->next;
    node->next->pre = node->pre;
}

//将node添加到当前频率的链表表尾
void ADD_node(LFUCache* obj, struct hashMapNode* node){
    int f = node->fre;
    if(obj->head[f] == NULL){
        obj->head[f] = node;
        obj->tail[f] = node;
        node->pre = NULL;
        node->next = NULL;
        return;
    }
    obj->tail[f]->next = node;
    node->pre = obj->tail[f];
    node->next = NULL;
    obj->tail[f] = node;
}

int lFUCacheGet(LFUCache* obj, int key) {
    if(!obj) return -1;
    struct hashMapNode* node = NULL;
    HASH_FIND_INT(obj->hashMap,&key,node);
    if(!node) return -1;
    //更新key值应该在的链表
    DEL_node(obj,node);
    if(obj->minf == node->fre && obj->head[node->fre] == NULL)
        obj->minf++;
    node->fre++;
    ADD_node(obj,node);

    return node->val;
}

void lFUCachePut(LFUCache* obj, int key, int value) {
    if(!obj->maxL) return;
    struct hashMapNode* node = NULL;
    HASH_FIND_INT(obj->hashMap,&key,node);
    if(node){
        DEL_node(obj,node);
        if(obj->minf == node->fre && obj->head[node->fre] == NULL)
            obj->minf++;
        node->fre++;
        node->val = value;
        ADD_node(obj,node);
        return;
    }
    node = malloc(sizeof(struct hashMapNode));
    node->key = key;
    node->val = value;
    node->fre = 1;
    if(obj->maxL == obj->currL){
        struct hashMapNode* tmp = obj->head[obj->minf];
        DEL_node(obj,obj->head[obj->minf]);
        HASH_DEL(obj->hashMap,tmp);
        obj->currL--;
    }
    ADD_node(obj,node);
    HASH_ADD_INT(obj->hashMap,key,node);
    obj->minf = 1;
    obj->currL++;
    return;
}

void lFUCacheFree(LFUCache* obj) {
    struct hashMapNode* tmp,* node;
    HASH_ITER(hh,obj->hashMap,tmp,node){
        HASH_DEL(obj->hashMap,tmp);
        free(tmp);
    }
    free(obj->head);
    free(obj->tail);
    free(obj);
}

/**
 * Your LFUCache struct will be instantiated and called as such:
 * LFUCache* obj = lFUCacheCreate(capacity);
 * int param_1 = lFUCacheGet(obj, key);
 
 * lFUCachePut(obj, key, value);
 
 * lFUCacheFree(obj);
*/
