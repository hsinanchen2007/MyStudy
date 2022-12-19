### 解题思路
POP操作时间复杂度不达标

### 代码

```c
typedef struct listNode {
    int val;
    struct listNode *next;
} LISTNODE;


typedef struct {
    int maxval;
    LISTNODE *back;
    LISTNODE *front;
} MaxQueue;


MaxQueue* maxQueueCreate() {
    MaxQueue *mq = (MaxQueue*)malloc(sizeof(MaxQueue));
    (void)memset(mq, 0, sizeof(MaxQueue));
    mq->maxval = -1;
    return mq;
}

int maxQueueMax_value(MaxQueue* obj) {
    return obj->maxval;
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    LISTNODE *node = (LISTNODE*)malloc(sizeof(LISTNODE));
    node->val = value;
    node->next = NULL;

    obj->maxval = fmax(value, obj->maxval);

    if (obj->back == NULL) {
        obj->front = obj->back = node;
    } else {
        obj->back->next = node;
        obj->back = node;
    }
}

int maxQueuePop_front(MaxQueue* obj) {
    if (obj->front == NULL) return -1;

    LISTNODE *front = obj->front;
    obj->front = front->next;
    if (obj->front == NULL) obj->back = NULL;/////
    int val = front->val;
    free(front);

    if (val == obj->maxval) {
        LISTNODE *tmp  = obj->front;
        obj->maxval = -1;
        while (tmp) {
            obj->maxval = fmax(obj->maxval, tmp->val);
            tmp = tmp->next;
        }
    }

    return val;
}

void maxQueueFree(MaxQueue* obj) {
    LISTNODE *cur = obj->front;
    LISTNODE *tmp;
    while (cur) {
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    free(obj);
}

/**
 * Your MaxQueue struct will be instantiated and called as such:
 * MaxQueue* obj = maxQueueCreate();
 * int param_1 = maxQueueMax_value(obj);
 
 * maxQueuePush_back(obj, value);
 
 * int param_3 = maxQueuePop_front(obj);
 
 * maxQueueFree(obj);
*/
```