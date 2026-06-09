### 解题思路
替换时比较频率和当频率相同时时间大者即可。

### 代码

```c
typedef struct MyLFUCache{
    int key;
    int value;
    int freq;
    int time;
    struct MyLFUCache * next;    
} LFUCache;


LFUCache* lFUCacheCreate(int capacity) { //初始化
    if(capacity==0) return NULL;
    LFUCache* obj = (LFUCache*)malloc(sizeof(LFUCache));
    obj->key=-1;
    obj->value=0;
    obj->freq=0;
    obj->time=0;
    obj->next=NULL;
    LFUCache * pre=obj;
    for(int i=0;i<capacity-1;i++){
        LFUCache* n = (LFUCache*)malloc(sizeof(LFUCache));
        n->key=0;
        n->value=0;
        n->freq=0;
        n->time=0;
        n->next=NULL;
        pre->next=n;
        pre=pre->next;
    }
    return obj;
}

int lFUCacheGet(LFUCache* obj, int key) {
    if(obj==NULL) return -1;   //空时get不到 返回-1
    int log=0,temp=obj->value;
    LFUCache *pre=obj;
    while(pre){               
        if(pre->key!=key){
            pre->time++;
        }else{
            log=1;
            temp=pre->value;
            pre->freq++;
            pre->time=0;
        }
        pre=pre->next;
    }
    return log?temp:-1;
}

void lFUCachePut(LFUCache* obj, int key, int value) {
    if(obj==NULL) return;  //空时直接返回
    int log=0;
    LFUCache *pre=obj;
    while(pre){
        if(pre->key==key){
            pre->value=value;
            pre->time=0;
            pre->freq++;
            log=1;
        }else{
            pre->time++;
        }
        pre=pre->next;
    }
    pre=obj;
    if(!log){
        LFUCache *opt=pre;
        int t_freq=pre->freq;
        int t_time=pre->time;
        while(pre->next){
            if(pre->next->freq<t_freq||(pre->next->freq==t_freq&&pre->next->time>t_time)){ //频率小者或频率相同时时间大者替换
                opt=pre->next;
                t_freq=pre->next->freq;
                t_time=pre->next->time;
            }
            pre=pre->next;
        }
        opt->key=key;
        opt->value=value;
        opt->time=0;
        opt->freq=1;
    }
}

void lFUCacheFree(LFUCache* obj) {
    LFUCache *pre=obj;
    while(obj){
        obj=obj->next;
        free(pre);
        pre=obj;
    }
}



```