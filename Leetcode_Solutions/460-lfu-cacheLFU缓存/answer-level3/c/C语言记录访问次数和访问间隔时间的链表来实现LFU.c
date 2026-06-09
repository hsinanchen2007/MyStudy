### 解题思路

花了3个小时。感觉思路不难呀，只是写起来怎么这么费劲。。。  

在头节点obj中，key存储缓存中的元素个数，value存储当前缓存的容量。obj后面的才是缓存中的内容。  
每个链表节点除了key，value分别存储键和值外，还有记录访问次数的freq，记录间隔上一次访问时长的time。next指针指向下一个链表节点。  
（操作的时候注意freq和time的值更新即可）  

- lFUCacheCreate()函数中，使用循环将分配capacity个链表节点。

- lFUCacheGet()函数中，循环遍历整个链表，遍历过程中每个节点的time都加1。如果有key则取出值，此时将这个节点的time设置为0，freq加1。

- lFUCachePut()函数中，先遍历一遍链表判断key是否在链表中，如果在则更新值value即可（freq和time的更新策略和Get函数中一样）。如果链表中没有key，则下面分两种情况
    1. 缓存空间未满，需要在缓存空间的末尾加上新的(key, value)。  
    2. 缓存空间满了，需要找出链表中freq最小的那个元素的位置，如果freq相同，则再比较一下time。找到了则将新的key, value赋给这个链表节点。

- lFUCacheFree()函数，循环遍历链表，每个节点都要释放空间。

### 代码

```c
typedef struct MyLFUCache{
    int key;
    int value;
    int freq;  // 使用次数
    int time;  // 距离最近一次使用的时间长度
    struct MyLFUCache *next;
} LFUCache;


LFUCache* lFUCacheCreate(int capacity) {
    LFUCache* obj = (LFUCache*)malloc(sizeof(LFUCache));
    obj->key = 0;  // obj里的key标记当前缓存中键的个数
    obj->value = capacity;  // obj里的value标记当前缓存容量
    obj->next = NULL; 
    LFUCache *curr = obj;
    for(int i=0; i<capacity; i++){
        LFUCache* node = (LFUCache*)malloc(sizeof(LFUCache));
        node->next = NULL;
        curr->next = node;
        curr = node;
    }
    return obj;
}

int lFUCacheGet(LFUCache* obj, int key) {
    int value = -1;
    LFUCache *curr = obj;
    for(int i=0; i < obj->key; i++){
        curr->next->time += 1;
        if(key == curr->next->key){
            value = curr->next->value;
            curr->next->freq += 1;
            curr->next->time = 0;
        }
        curr=curr->next;
    }
    return value;
}

void lFUCachePut(LFUCache* obj, int key, int value) {
    int i, flag=0;
    LFUCache *curr = obj;
    for(i=0; i < obj->key; i++){
        curr->next->time += 1;
        if(curr->next->key == key){
            curr->next->value = value;
            curr->next->freq += 1;
            curr->next->time = 0;
            flag = 1;
        }
        curr=curr->next;
    }
    // 如果缓存中没有key
    if(flag == 0  && obj->value > 0){
        if(obj->key < obj->value){  //缓存未满
            obj->key += 1;
            curr = curr->next;
        }else{  // 缓存满了
            LFUCache *sel = obj->next;
            curr = obj;
            for(i=0; i < obj->key; i++){
                // LRU, 选出频率最小的那个，频率相同选出上次访问间隔最久的那个
                if(curr->next->freq < sel->freq){
                    sel = curr->next;
                }else if((curr->next->freq == sel->freq) && (curr->next->time > sel->time)){
                    sel = curr->next;
                }
                curr = curr->next;
            }
            curr = sel;
        }
        curr->key = key;
        curr->value = value;
        curr->freq = 1;
        curr->time = 0;
    }
}

void lFUCacheFree(LFUCache* obj) {
    LFUCache *node;
    while(obj->next != NULL){
        node = obj->next;
        obj->next = node->next;
        free(node);
    }
    free(obj);
}

```