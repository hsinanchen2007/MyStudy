### 解题思路
　与单向循环队列类似，预留一个空间来区分空队列和满队列。
-1操作可以通过加模平移避免负数无法求余。
### 代码

```c
typedef struct {
    int *data;
    int head;
    int rear;
    int max_size;
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *temp = NULL;
    temp = (MyCircularDeque *)calloc(sizeof(MyCircularDeque), 1);
    temp->data = (int *)malloc(sizeof(int)*(k+1));
    temp->max_size = k + 1;
    temp->head = 0;
    temp->rear = 0;
    return temp;
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if(obj->head == obj->rear)
        return true;
    else
        return false;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if(obj->head == (obj->rear + 1)%obj->max_size)
        return true;
    else
        return false;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(myCircularDequeIsFull(obj))
        return false;
    else
    {
        obj->head = (obj->head - 1 +obj->max_size)%obj->max_size;
        obj->data[obj->head] = value;
        return true;
    }  
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(myCircularDequeIsFull(obj))
        return false;
    else
    {
        obj->data[obj->rear] = value;
        obj->rear = (obj->rear + 1)%obj->max_size;
        return true;
    }   
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj))
        return false;
    else
    {
        obj->head = (obj->head + 1)%obj->max_size;
        return true;
    }
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj))
        return false;
    else
    {
        obj->rear = (obj->rear - 1 + obj->max_size)%obj->max_size;
        return true;
    }    
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj))
        return -1;
    else
        return obj->data[obj->head];
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj))
        return -1;
    else
        return obj->data[(obj->rear - 1 + obj->max_size)%obj->max_size];
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->data);
    free(obj);    
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/
```