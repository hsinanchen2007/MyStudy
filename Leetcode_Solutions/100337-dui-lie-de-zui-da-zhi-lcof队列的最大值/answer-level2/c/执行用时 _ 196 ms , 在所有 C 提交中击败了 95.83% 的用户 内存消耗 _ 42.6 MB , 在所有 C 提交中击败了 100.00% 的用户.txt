这题关键的地方在于审题，题目中说的是平均复杂度为O（1），所以对于大部分情况复杂度为O(1)就可以了。对于本题，主要在于弹出队首元素的时候需要考虑，两种情况：
1.弹出的值小于当前的最大值，那么不用做什么特殊操作，直接弹出即可
2.弹出的值等于当前的最大值，那么需要对整个队列搜索一遍，刷新最大值。
而1的情况明显要比情况2出现的概率高。所以平均复杂度为1。
```
typedef struct queue{
    struct queue *next;
    int val;
    int maxNum;
} MaxQueue;

MaxQueue *tail = NULL;
MaxQueue* maxQueueCreate() {
   // printf("maxQueueCreate\n");
    MaxQueue *dummy = (MaxQueue *)malloc(sizeof(MaxQueue));
    dummy->next = NULL;
    dummy->val = 0;
    dummy->maxNum = -1;
    tail = dummy;
    return dummy;
}

int maxQueueMax_value(MaxQueue* obj) {
   // printf("maxQueueMax_value\n");
    if (obj->next == NULL) {
        return -1;
    }
    return tail->maxNum;
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    //printf("maxQueuePush_back\n");
    int max = tail->maxNum;
    tail->next = malloc(sizeof(MaxQueue));
    tail = tail->next;
    tail->next = NULL;
    tail->val = value;
    if (value > max) {
        tail->maxNum = value;
    } else {
        tail->maxNum = max;
    }
    return;
}

int maxQueuePop_front(MaxQueue* obj) {   
   // printf("maxQueuePop_front\n");
    if (obj->next == NULL) {
        return -1;
    }
    MaxQueue *popNode = obj->next;
    int popNum = popNode->val;

    /*刷新最大值*/
    if (popNum == tail->maxNum) {
        int newMax = 0;
        MaxQueue *tmp = popNode->next;
        while (tmp != NULL) {
            if (tmp->val > newMax) newMax = tmp->val;
            tmp = tmp->next;
        }
        tail->maxNum = newMax;
    }
    // 剩一个元素，处理tail的特殊情况
    if (popNode == tail) tail = obj;

    obj->next = popNode->next;
    free(popNode);
    return popNum;
}

void maxQueueFree(MaxQueue* obj) {
   // printf("maxQueueFree\n");
    //释放需要先暂存释放节点，再释放
    MaxQueue *tmp;
    while(obj != NULL) {
        tmp = obj;
        obj = obj->next;
        free(tmp);
    }
}

```
