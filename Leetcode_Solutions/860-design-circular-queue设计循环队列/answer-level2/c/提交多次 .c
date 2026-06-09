### 解题思路
提交多次才勉强通过，不亲自敲总觉得简单的典型题目
尤其是临界条件下头尾指针要不要更新
### 代码

```c



typedef struct {
    int* queue;
    int head;
    int tail;
    int cap;
    int curSize;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* newQueue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    newQueue->queue = (int*)malloc(sizeof(int)*k);
    memset(newQueue->queue, 0, sizeof(int)*k);
    newQueue->head = 0;
    newQueue->tail = 0;
    newQueue->cap = k;
    newQueue->curSize = 0;
    return newQueue;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(obj == NULL || obj->curSize >= obj->cap ) {
        return false;
    }
    if(obj->curSize==0){
        obj->queue[obj->tail] = value;
    }else if(obj->tail < obj->cap-1){
        obj->tail++;
        obj->queue[obj->tail] = value;
    }else if(obj->tail == obj->cap-1){
        obj->tail = 0;
        obj->queue[0] = value;
    }
    obj->curSize++;
    //printf("EnQueue size= %d cap= %d 0=%d 1=%d head=%d rear=%d\n",obj->curSize, obj->cap, obj->queue[0], obj->queue[1], obj->head, obj->tail);
    return true;
  

    
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    /* 除了初始化的时候首尾不应该相等 */
    if(obj == NULL || obj->curSize == 0) {
        return false;
    }
    if(obj->curSize==1 && obj->head==obj->tail){
       
    }else if(obj->head<obj->cap-1) {
        obj->head++;
    }else if(obj->head == obj->cap-1) {
        obj->head=0;
    }
    obj->curSize--;
    //printf("DeQueue size= %d cap= %d head=%d rear=%d \n",obj->curSize, obj->cap, obj->head, obj->tail);
    return true;        
 
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
  //printf("Front size= %d cap= %d 0=%d 1=%d\n",obj->curSize, obj->cap, obj->queue[0], obj->queue[1]);
  if(obj->curSize != 0){

      return obj->queue[obj->head];
  }
  return -1;
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    //printf("Rear tail=%d head=%d curSize=%d num=%d %d %d %d\n",obj->tail,obj->head,obj->curSize,obj->queue[obj->tail],obj->queue[0], obj->queue[1],obj->queue[2]);
    
     if(obj->curSize != 0){

      return obj->queue[obj->tail];
  }
  return -1;

}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  if(obj->curSize == 0){
       return true;
  }

    return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
   if(obj->curSize == obj->cap) {
       return true;
   }
    return false;
   
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if(obj->queue != 0) {
       free(obj->queue);
       free(obj);
   }
    return;
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
```