算法如下：
typedef struct {
    int *s1;
    int *s2;
    int len1;
    int len2;
} CQueue;


CQueue* cQueueCreate() {
    CQueue * qlist = (CQueue *)malloc(sizeof(CQueue));
    qlist->s1 = (int *)malloc(sizeof(int)*10000);
    qlist->s2 = (int *)malloc(sizeof(int)*10000);
    qlist->len1 = 0;
    qlist->len2 = 0;
    return qlist;
}

void cQueueAppendTail(CQueue* obj, int value) {
    if(obj->len1 <= 10000) ;
        obj->s1[++obj->len1] = value;
}

int cQueueDeleteHead(CQueue* obj) {
    if(obj->len2==0 && obj->len1 == 0) return -1;
    if(obj->len2>0) return obj->s2[obj->len2--];
    else {
        while(obj->len1>0){
            obj->s2[++obj->len2]=obj->s1[obj->len1--]; 
        }
        return obj->s2[obj->len2--];
        
    }
}

void cQueueFree(CQueue* obj) {
    free(obj->s1);
    free(obj->s2);
    free(obj);
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/