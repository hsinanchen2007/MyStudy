```
```c
typedef struct {
    int *data;
    int head;
    int tail;
    int cap;
} MyCircularQueue;
/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *queue = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    queue -> data = (int *)malloc((k + 1) * sizeof(int)); //模拟动态数组，留出一位空闲
    queue -> head = 0;
    queue -> tail = 0;
    queue -> cap  = k + 1; 
    return queue;
}
/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  if(obj -> head == obj -> tail){
      return true;
  }
    return false;
}
/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
  if(obj -> head == (obj -> tail + 1) % (obj -> cap)){
      return true;
  }
  return false;
}
/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj) == true){
        return false;
    }
    obj -> data[obj -> tail] = value;//First In
    obj -> tail = (obj -> tail + 1) % (obj -> cap); //索引 + 1，并且要注意取模计算,实现循环队列
    return true;
}
/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj) == true){
        return false;
    }
    obj -> head = (obj -> head + 1) % (obj -> cap);
    return true;
}
/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj) == true){
        return -1;
    }else{
        return obj ->data[obj -> head];   
    }
}
/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj) == true){
        return -1;
    }
        return obj -> data[(obj-> tail - 1 + obj -> cap) % (obj -> cap)]; //注意处理
}
void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj -> data);
    obj -> data = NULL;
    free(obj);
    obj = NULL;
}
```
```
