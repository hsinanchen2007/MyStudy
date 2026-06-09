### 代码

```c
typedef struct {
    int key;
    int value;
    int valid;  // 有效位
    int tag[2];  // LFU辅助位,访问次数，上次访问
} LFUCache;

// 0位置作为特殊标记，value为访问次数，tag[0]为最大容量，tag[1]为使用量
LFUCache* lFUCacheCreate(int capacity) {
    int i=0;
    LFUCache *cache=(LFUCache *)malloc(sizeof(LFUCache)*(capacity+1));
    cache[0].tag[0]=capacity;
    cache[0].tag[1]=0;
    cache[0].value=0;
    for(i=1;i<cache[0].tag[0]+1;i++){
        cache[i].valid=0;
        cache[i].tag[0]=0;
        cache[i].tag[1]=0;
    }
    return cache;
}

int lFUCacheGet(LFUCache* obj, int key) {
  int i=1;
  obj[0].value++;  // 每一次GET更新
//   printf("get number%d,tag0:%d,\n",obj[0].value,obj[0].tag[0]);
  for(;i<obj[0].tag[0]+1;i++){
    // printf("%d,%d,%d\n",i,obj[i].valid,obj[i].key);
    if((obj[i].valid)&&(key==obj[i].key)) {
        // status
        obj[i].tag[1]=obj[0].value;
        obj[i].tag[0]++; // 访问次数
        // printf("访问%d,key%d,频度%d,上次访问%d\n",i,obj[i].key,obj[i].tag[0],obj[i].tag[1]);
        return obj[i].value;
    }
  }
  return -1;
}

void lFUCachePut(LFUCache* obj, int key, int value) {
    int i,geti=1;
    // min=obj[1].tag[0];
    if(obj[0].tag[0]==0) return;
    obj[0].value++;
    // printf("占用:%d,容量:%d\n",obj[0].tag[1],obj[0].tag[0]);
    for(i=1;i<obj[0].tag[0]+1;i++){
        if(obj[i].key==key){
            obj[i].value=value;
            obj[i].key=key;
            obj[i].valid=1;
            obj[i].tag[0]++;
            obj[i].tag[1]=obj[0].value;
            // obj[0].tag[1]++;
            return;
        }
    }
    if(obj[0].tag[1]>=obj[0].tag[0]){
        for(i=1;i<obj[0].tag[0]+1;i++){
            if(obj[geti].tag[0]>obj[i].tag[0]) {geti=i;}
            else if(obj[geti].tag[0]==obj[i].tag[0]){
                if(obj[i].tag[1]<obj[geti].tag[1])
                    geti=i;
            }
        }
        obj[geti].valid=0;
        obj[0].tag[1]--;
    }
    if(obj[0].tag[1]<obj[0].tag[0])
        for(i=1;i<obj[0].tag[0]+1;i++){
            if(obj[i].valid==0) {
                // printf("插入%d,key%d,value%d\n",i,key,value);
                obj[i].value=value;
                obj[i].key=key;
                obj[i].valid=1;
                obj[i].tag[0]=0;
                obj[i].tag[1]=obj[0].value;
                obj[0].tag[1]++;
                break;
            }
        }
}

void lFUCacheFree(LFUCache* obj) {
    free(obj);
}

/**
 * Your LFUCache struct will be instantiated and called as such:
 * LFUCache* obj = lFUCacheCreate(capacity);
 * int param_1 = lFUCacheGet(obj, key);
 
 * lFUCachePut(obj, key, value);
 
 * lFUCacheFree(obj);
*/
```