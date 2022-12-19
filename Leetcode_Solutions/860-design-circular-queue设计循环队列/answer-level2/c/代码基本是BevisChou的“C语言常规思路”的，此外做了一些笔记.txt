### 解题思路
    首先用结构体把数组（指针），储存头节点，尾节点，还有长度信息的变量封装起来。对于指针指向的区域，首先申请一个指向结构体的指针，然后再用长度k和待储存的类型的乘积的形式申请好相当于数组的空间，哎没有写如果malloc申请失败的语句啊。
    只看过一点大话数据结构，这里的实现和书上的例子不是太一样，它是把所有的空间都用上了的。好像这个代码的逻辑是有点欠缺的，在判断对列是否full的时候有一句这个东西obj->head==obj->rear+1；如果只满足这个条件，实际上队列为空或者为满都是能满足要求的。但是作为萌新的我们还是不妨先跟着敲敲。
    第三点要说的函数顺序的问题，按照力扣初始给的函数顺序编写是通不过的，要把一些基本的函数先调到前面来
    最后感谢BevisChou！
### 代码

```c
typedef struct myQueue{
    int* queue;
    int head;
    int rear;
    int size;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue * obj = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    obj->queue=malloc(k*sizeof(int));
    obj->head=0;
    obj->rear=0;
    obj->size=k;
    while(k){
        (obj->queue)[--k]=-1;
    }
    return obj;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  return ((obj->head==obj->rear)&&((obj->queue)[obj->head]==-1));

}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
  return(obj->head==0&&obj->rear==obj->size-1||obj->head==obj->rear+1);
  //这个和大话数据结构上的是不太一样的
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj)){
        return 0;
    }
    else if(myCircularQueueIsEmpty(obj)){
        (obj->queue)[obj->head]=value;
        return 1;
    }
    obj->rear++;
    if(obj->rear==obj->size){
        obj->rear=obj->rear-obj->size;
    }else if(obj->rear==obj->head){
            return 0;
    }
    (obj->queue)[obj->rear]=value;
    return 1;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return 0;
    }
    (obj->queue)[obj->head]=-1;
    if(obj->head!=obj->rear){
        obj->head++;
    }
    return 1;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    return (obj->queue)[obj->head];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    return (obj->queue)[obj->rear];
}


void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
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
```