![image.png](https://pic.leetcode-cn.com/c964267009f840130a21cd971632e07a17ff17f4768ef5874c3acdf3b17cdb32-image.png)

typedef struct {
    int len;
    int *stack1;
    int *stack2;
    int top1;
    int top2;
} CQueue;

CQueue* cQueueCreate() {
    CQueue *queue;
    queue=malloc(sizeof(CQueue));
    queue->len=10000;
    queue->stack1=malloc(queue->len*sizeof(int));
    queue->stack2=malloc(queue->len*sizeof(int));
    queue->top1=-1;
    queue->top2=-1;
    return queue;
}

/* 有数据就添加到stack1中 */
void cQueueAppendTail(CQueue* obj, int value) {
    obj->stack1[++obj->top1]=value;
}

/* stack1中的数据复制到stack2中，顺序正好是先进先进先出*/
int cQueueDeleteHead(CQueue* obj) {
    if(obj->top1==-1 && obj->top2==-1)
    return -1;
    /* top2为-1时，复制stack1中数据，否则打乱stack2中之前存储的数据 */
    if(obj->top2==-1){
        while(obj->top1!=-1){
            obj->stack2[++obj->top2]=obj->stack1[obj->top1--];
        }
    }
    return obj->stack2[obj->top2--];
}

void cQueueFree(CQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/
