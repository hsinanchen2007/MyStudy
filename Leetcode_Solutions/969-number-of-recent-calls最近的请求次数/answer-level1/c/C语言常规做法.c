使用回旋数组实现队列，注意数组长度为3001。
```c
typedef struct {
    int *queue;
    int head;
    int tail;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    int i=3000;
    RecentCounter *obj=malloc(sizeof(RecentCounter));
    obj->head=0;
    obj->tail=0;
    obj->queue=malloc(3001*sizeof(int));
    while(i>=0) (obj->queue)[i--]=-1;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    while((obj->queue)[obj->head]<t-3000&&(obj->queue)[obj->head]!=-1){
        (obj->queue)[obj->head]=-1;
        if((obj->queue)[obj->tail]!=-1) obj->head++;
        if(obj->head>3000) obj->head=obj->head-3001;
    }
    if((obj->queue)[obj->tail]!=-1) obj->tail++;
    if(obj->tail>3000) obj->tail=obj->tail-3001;
    (obj->queue)[obj->tail]=t;
    return obj->tail>=obj->head?obj->tail-obj->head+1:obj->tail+3002-obj->head;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->queue);
    free(obj);
}
```