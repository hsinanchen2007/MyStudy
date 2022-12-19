```
typedef struct {
    int *que;
    int len;
    int head; /* 指向队头的下一个空闲位置 */
    int tail; /* 指向队尾元素 */
    int cnt;
} MyCircularDeque;
/** Initialize your data structure here. Set the size of the deque to be k. */
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = calloc(1, sizeof(MyCircularDeque));
    obj->que = calloc(k, sizeof(int));
    obj->len = k;
    return obj;
}
/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->cnt == obj->len) {
        return false;
    }
    obj->que[obj->head++] = value;
    obj->head %= obj->len;
    obj->cnt++;
    return true;
}
/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->cnt == obj->len) {
        return false;
    }
    obj->tail = (obj->tail + obj->len - 1) % obj->len;  /* 队尾插入，先移动后添加 */
    obj->que[obj->tail] = value;
    obj->cnt++;
    return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->cnt == 0) {
        return false;
    }
    obj->head = (obj->head + obj->len - 1) % obj->len; /* 队列头退1 */
    obj->cnt--;
    return true;
}
/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->cnt == 0) {
        return false;
    }
    obj->tail = (obj->tail + 1) % obj->len; /* 队列尾进1 */
    obj->cnt--;
    return true;
}
/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->cnt == 0) {
        return -1;
    }
    int idx = (obj->head + obj->len - 1) % obj->len;  /* 避免减法溢出 */
    return obj->que[idx];
}
/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->cnt == 0) {
        return -1;
    }
    return obj->que[obj->tail];
}
/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if (obj->cnt == 0) {
        return true;
    }
    return false;
}
/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if (obj->cnt == obj->len) {
        return true;
    }
    return false;    
}
void myCircularDequeFree(MyCircularDeque* obj) {
    if (obj->que != NULL) {
        free(obj->que);
    }
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
