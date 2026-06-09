### 解题思路
摘抄voyagerhui的代码


### 代码

```c

typedef struct CacheNode{
    int key;
    int value;
    int freq;  
    int time;  
    struct CacheNode *next;
} LFUCache;

LFUCache* lFUCacheCreate(int capacity) {
    LFUCache* obj = (LFUCache*)malloc(sizeof(LFUCache));
    obj->key = 0; 
    obj->value = capacity;  
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

    if(flag == 0  && obj->value > 0){
        if(obj->key < obj->value){  
            obj->key += 1;
            curr = curr->next;
        }else{  
            LFUCache *sel = obj->next;
            curr = obj;
            for(i=0; i < obj->key; i++){
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