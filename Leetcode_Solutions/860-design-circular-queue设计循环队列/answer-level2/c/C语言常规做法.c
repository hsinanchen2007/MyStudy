该题代码实现较为常规，不再赘述。
需要注意释放内存空间时，先释放obj->queue，再释放obj。
```c
typedef struct myQueue{
    int* queue;
    int head;
    int tail;
    int size;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj=malloc(sizeof(MyCircularQueue));
    obj->queue=malloc(k*sizeof(int));
    obj->head=0;
    obj->tail=0;
    obj->size=k;
    while(k) (obj->queue)[--k]=-1;
    return obj;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->head==obj->tail)&&((obj->queue)[obj->head]==-1);
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->head==0&&obj->tail==obj->size-1)||obj->head==obj->tail+1;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj)) return 0;
    if(myCircularQueueIsEmpty(obj)){
        (obj->queue)[obj->head]=value;
        return 1;
    }
    obj->tail++;
    if(obj->tail==obj->size) obj->tail=obj->tail-obj->size;
    if(obj->tail==obj->head) return 0;
    (obj->queue)[obj->tail]=value;
    return 1;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) return 0;
    (obj->queue)[obj->head]=-1;
    if(obj->head!=obj->tail) obj->head++;
    return 1;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    return (obj->queue)[obj->head];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    return (obj->queue)[obj->tail];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    free(obj);
}
```