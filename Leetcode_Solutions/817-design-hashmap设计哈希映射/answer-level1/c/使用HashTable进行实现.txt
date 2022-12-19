#define BUCKET_SIZE 1000
#define HASH(k) ((k)%BUCKET_SIZE)

// 双向链表，默认有一个head节点
struct list_head {
    struct list_head *pre;
    struct list_head *next;    
    int key;
    int val;
};

static inline void list_init(struct list_head *head)
{
    head->next = head;
    head->pre = head;
}

static inline void list_add(struct list_head *head, struct list_head *cur)
{
    head->next->pre = cur;
    cur->next = head->next;
    cur->pre = head;
    head->next = cur;    
}

static inline void list_remove(struct list_head *pos)
{
    pos->pre->next = pos->next;
    pos->next->pre = pos->pre;    
}

static inline void free_list(struct list_head *head)
{
    struct list_head *tmp = head->next;
    struct list_head *freeNode = tmp;
    for (; tmp != head;) {
        freeNode = tmp;
        tmp = tmp->next;
        free(freeNode);
    }
}

struct list_head *list_find(struct list_head *head, int key)
{
    struct list_head *tmp = head->next;
    for (; tmp != head; tmp = tmp->next) {
        if (tmp->key == key) {
            return tmp;
        }
    }
    return NULL;
}

typedef struct {
    struct list_head head;
    int listCnt;
} Bucket;

typedef struct {
    Bucket *buckets;
    int bucketCnt;    
} MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
    MyHashMap *hashSet = (MyHashMap *)malloc(sizeof(MyHashMap));
    hashSet->buckets = (Bucket *)malloc(sizeof(Bucket) * BUCKET_SIZE);
    hashSet->bucketCnt = BUCKET_SIZE;
    int i;
    for (i = 0; i < BUCKET_SIZE; i++) {        
        list_init(&(hashSet->buckets[i].head));
        hashSet->buckets[i].listCnt = 0;
    }
    return hashSet;    
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
    int bucketInx = HASH(key);
    Bucket *bucket = &obj->buckets[bucketInx];
    struct list_head *node = list_find(&(bucket->head), key);
    if (node != NULL) {
        node->val = value;
        return;
    }
    // 不存在则新插入
    struct list_head *newNode = (struct list_head *)malloc(sizeof(struct list_head));
    newNode->key = key;
    newNode->val = value;
    list_add(&(bucket->head), newNode);
    bucket->listCnt++;  
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
    int bucketInx = HASH(key);
    Bucket *bucket = &obj->buckets[bucketInx];
    struct list_head *node = list_find(&(bucket->head), key);
    if (node != NULL) {
        return node->val;
    }
    return -1;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
    int bucketInx = HASH(key);
    Bucket *bucket = &obj->buckets[bucketInx];
    struct list_head *node = list_find(&(bucket->head), key);
    if (node == NULL) {
        return;
    }
    list_remove(node);
    free(node);
}

void myHashMapFree(MyHashMap* obj) {
    int i;
    for (i = 0; i < obj->bucketCnt; i++) {
        free_list(&(obj->buckets[i].head));
    }
    free(obj->buckets);
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

