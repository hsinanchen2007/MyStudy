### 解题思路
- obj作为队列的指针，里面有head：指向队列首元素；tail：指向队列尾元素；max：指向队列节点中值最大的元素。
- 队列节点中，value存储节点的值，tail指向下一个节点。
出队入队都是基本操作，只是注意指针的指向。
但是出队的时候，需要额外判断一下出队的节点是不是值最大的节点，如果是则需要在后面while查找一遍，找到新的最大的值，然后obj的max指针指向它。

### 代码

```c
typedef struct MyMaxQueue{
    int value;
    struct MyMaxQueue* head;
    struct MyMaxQueue* tail;
    struct MyMaxQueue* max;
} MaxQueue;


MaxQueue* maxQueueCreate() {
    MaxQueue* obj = (MaxQueue*)malloc(sizeof(MaxQueue));
    obj->head = NULL;
    obj->tail = NULL;
    obj->max = NULL;
    return obj;
}

int maxQueueMax_value(MaxQueue* obj) {
    if(obj->head == NULL){
        return -1;
    }else{
        return obj->max->value;
    }
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    MaxQueue* node = (MaxQueue*)malloc(sizeof(MaxQueue));
    node->value = value;
    node->tail = NULL;
    if(obj->head == NULL){
        obj->head = node;
        obj->tail = node;
        obj->max = node;
    }else{
        obj->tail->tail = node;
        obj->tail = node;
        if(value > (obj->max->value)){
            obj->max = node;
        }
    }
}

int maxQueuePop_front(MaxQueue* obj) {
    int front_value;
    if(obj->head == NULL){
        return -1;
    }else{
        MaxQueue *front;
        front = obj->head;
        front_value = obj->head->value;
        if(front->tail == NULL){
            obj->head = NULL;
        }else{
            obj->head = front->tail;
            if(obj->max == front){  // 如果出队的节点是最大值所在的节点，需要遍历整个队列重新找到最大值
                int max_value;
                MaxQueue* curr = obj->head;
                obj->max = obj->head;
                while(curr != NULL){
                    if(curr->value > obj->max->value){
                        obj->max = curr;
                    }
                    curr = curr->tail;
                }
            }
        }
        free(front);
    }
    return front_value;
}

void maxQueueFree(MaxQueue* obj) {
    MaxQueue *curr, *prev;
    curr = obj->head;
    while(curr != NULL){
        prev = curr;
        curr = curr->tail;
        free(prev);
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