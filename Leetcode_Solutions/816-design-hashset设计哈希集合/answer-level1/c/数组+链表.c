#define BUCKET_SIZE 100
#define HASH(k) ((k)%BUCKET_SIZE)

// 双向链表，默认有一个head节点
struct list_head {
    struct list_head *pre;
    struct list_head *next;    
    int val;
};

void list_init(struct list_head *head)
{
    head->next = head;
    head->pre = head;
}

void list_add(struct list_head *head, struct list_head *cur)
{
    head->next->pre = cur;
    cur->next = head->next;
    cur->pre = head;
    head->next = cur;    
}

void list_remove(struct list_head *pos)
{
    pos->pre->next = pos->next;
    pos->next->pre = pos->pre;    
}

void free_list(struct list_head *head)
{
    struct list_head *tmp = head->next;
    struct list_head *freeNode = tmp;
    for (; tmp != head;) {
        freeNode = tmp;
        tmp = tmp->next;
        free(freeNode);
    }
}

struct list_head *list_find(struct list_head *head, int val)
{
    struct list_head *tmp = head->next;
    for (; tmp != head; tmp = tmp->next) {
        if (tmp->val == val) {
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
} MyHashSet;

/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
    MyHashSet *hashSet = (MyHashSet *)malloc(sizeof(MyHashSet));
    hashSet->buckets = (Bucket *)malloc(sizeof(Bucket) * BUCKET_SIZE);
    hashSet->bucketCnt = BUCKET_SIZE;
    int i;
    for (i = 0; i < BUCKET_SIZE; i++) {        
        list_init(&(hashSet->buckets[i].head));
        hashSet->buckets[i].listCnt = 0;
    }
    return hashSet;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int bucketInx = HASH(key);
    Bucket *bucket = &obj->buckets[bucketInx];
    if (list_find(&(bucket->head), key) != NULL) {
        return;
    }
    struct list_head *newNode = (struct list_head *)malloc(sizeof(struct list_head));
    newNode->val = key;
    list_add(&(bucket->head), newNode);
    bucket->listCnt++;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int bucketInx = HASH(key);
    Bucket *bucket = &obj->buckets[bucketInx];
    struct list_head *node = list_find(&(bucket->head), key);
    if (node == NULL) {
        return;
    }
    list_remove(node);
    free(node);
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    int bucketInx = HASH(key);
    Bucket *bucket = &obj->buckets[bucketInx];
    struct list_head *node = list_find(&(bucket->head), key);
    if (node == NULL) {
        return false;
    }
    return true;
}

void myHashSetFree(MyHashSet* obj) {
    int i;
    for (i = 0; i < obj->bucketCnt; i++) {
        free_list(&(obj->buckets[i].head));
    }
    free(obj->buckets);
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

