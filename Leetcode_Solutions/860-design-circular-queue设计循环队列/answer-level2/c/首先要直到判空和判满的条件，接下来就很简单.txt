typedef struct {
    int* array;
    int  n;     // 数组空间大小
    int  front; // 队头
    int  rear;  // 队尾
} MyCircularQueue;

bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    cq->array = (int*)malloc(sizeof(int)*(k+1));
    cq->n = k+1;       //空间开 k+1个，但只能存k个，开 k+1 是为了方便判满和判空
    cq->front = 0;
    cq->rear = 0;

    return cq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj))   //判满
        return false;
    
    obj->array[obj->rear] = value;   
    obj->rear++;
    //obj->rear %= obj->n;   //方法一：取余 若尾超出则置0，实现了循环存储
    if(obj->rear == obj->n)   //方法二
        obj->rear = 0;

    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))   //判空
        return false;

    obj->front++;     //删除后头前移
    if(obj->front == obj->n)   //当头删除到和大小相等时，头置0，实现循环存储
        obj->front = 0;

    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))  //判空
        return -1;
    return obj->array[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
     if(myCircularQueueIsEmpty(obj))  //判空
        return -1;
        
    int prevRear = obj->rear-1;    //rear == k+1, 但实际只存储到 k处
    if(obj->rear == 0)    //尾在0处的情况
        prevRear = obj->n-1; 

    return obj->array[prevRear];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
     return obj->front == obj->rear;   //当头 == 尾 则为空
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    int rearNext = obj->rear+1;    
    rearNext %= obj->n;    // 满时 rear == k+1 处，+1 再取余则 置0 

    return rearNext == obj->front;   //此时 头 == 尾 则满
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->array);
    free(obj);
}


/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/