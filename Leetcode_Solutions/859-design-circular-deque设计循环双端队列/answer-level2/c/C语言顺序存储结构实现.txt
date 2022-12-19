这个设计题目一开始让我有点摸不着头脑，第一次接触所谓双端队列。但是我在题解去，看一个高赞回答的dalao解释后明白了所谓循环双端队列是什么玩意。
总结起来就一句话：队列中，rear和front职责分明，分别负责一头一尾（即分别管理进出），但是在双端队列中rear和front的职责共享。重要的是这告诉我们可以基于队列的条件去设置循环双端队列，我只需要对front和rear的操作共享化（即两者都可以管理进出）。那么队空队满的条件判断都可以基于队列来设计。好了下面是实现代码。
```
typedef struct MyCircularDeque 
{
    int front;
    int rear;
    int MAXSIZE;
    int data[];     //这是伸缩型数组成员,可以理解为动态数组，大小依据内存分配而定。不明白自行查阅
} MyCircularDeque;


bool myCircularDequeIsEmpty(MyCircularDeque* obj);
bool myCircularDequeIsFull(MyCircularDeque* obj);


/** Initialize your data structure here. Set the size of the deque to be k. */
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque) + (k + 1) * sizeof(int));
    if(!obj)
        return NULL;
    memset(obj, 0, sizeof(MyCircularDeque) + (k + 1) * sizeof(int));
    obj->MAXSIZE = k + 1;

    return obj;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(myCircularDequeIsFull(obj))
        return false;

    obj->front = (obj->front - 1 + obj->MAXSIZE) % obj->MAXSIZE;
    obj->data[obj->front] = value;
    return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(myCircularDequeIsFull(obj))
        return false;

    obj->data[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->MAXSIZE;
    return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj))
        return false;
    
    obj->front = (obj->front + 1) % obj->MAXSIZE;
    return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {  //OVER
    if(myCircularDequeIsEmpty(obj))
        return false;

     obj->rear = (obj->rear - 1 + obj->MAXSIZE) % obj->MAXSIZE;
     return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) { //OVER
    return myCircularDequeIsEmpty(obj) ? -1 : obj->data[obj->front];
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {  //OVER
    if(myCircularDequeIsEmpty(obj))
        return -1;

    int index = (obj->rear - 1 +obj->MAXSIZE) % obj->MAXSIZE;
    return obj->data[index];
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) { //OVER
    return obj->rear == obj->front ? true : false;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {  //OVER
    return (obj->rear +1) % obj->MAXSIZE == obj->front ? true : false;
}

void myCircularDequeFree(MyCircularDeque* obj) {    //OVER
    free(obj);
    obj = NULL;
}

```
