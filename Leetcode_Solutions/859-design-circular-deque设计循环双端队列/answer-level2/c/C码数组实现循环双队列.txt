### 解题思路
本题使用了数组和两个索引（front和last）实现，问题的关键有三处：
1. front和last的初始化分别使用-1和k；
2. 只有一个结点时，front和last要相同；
3. 队列为空的时候，front和last要还原为初始值。 

### 代码

```c
typedef struct {
    int *data;
    int front;
    int last;
    int count;
    int max;
} MyCircularDeque;

MyCircularDeque myDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */
MyCircularDeque* myCircularDequeCreate(int k) {
    memset(&myDeque, 0, sizeof(myDeque));    
    myDeque.data = (int *)malloc(k * sizeof(int));
    if (myDeque.data == NULL) {
        return NULL;
    }

    memset(myDeque.data, 0, sizeof(k * sizeof(int)));
    myDeque.max = k;
    myDeque.front = -1;
    myDeque.last = k;
    return &myDeque;
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if (obj->count == 0) {
        return true;
    }

    return false;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if (obj->count == obj->max) {
        return true;
    }

    return false;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) {
        return false;
    }
    obj->front = (obj->front + 1) % obj->max;
    obj->data[obj->front] = value;
    obj->count++;

    if (obj->count == 1) {
        obj->last = obj->front;
    }
    return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) {
        return false;
    }
    obj->last = (obj->last + obj->max - 1) % obj->max;
    obj->data[obj->last] = value;
    obj->count++;

    if (obj->count == 1) {
        obj->front = obj->last;
    }
    return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return false;
    }

    obj->front = (obj->front + obj->max - 1) % obj->max;
    obj->count--;
    if (obj->count == 0) {
        obj->front = -1;
        obj->last = obj->max;
    }
    return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return false;
    }

    obj->last = (obj->last + 1) % obj->max;
    obj->count--;
    if (obj->count == 0) {
        obj->front = -1;
        obj->last = obj->max;
    }
    return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->front == -1) {
        return -1;
    }
    return obj->data[obj->front];
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->last == obj->max) {
        return -1;
    }
    return obj->data[obj->last];
}

void myCircularDequeFree(MyCircularDeque* obj) {
    if (obj->data) {
        free(obj->data);
        obj->data = NULL;
    }
    memset(&myDeque, 0, sizeof(myDeque));
    return;
}
```

# 执行结果
执行用时 :40 ms, 在所有 C 提交中击败了71.68%的用户
内存消耗 :12.2 MB, 在所有 C 提交中击败了100.00%的用户