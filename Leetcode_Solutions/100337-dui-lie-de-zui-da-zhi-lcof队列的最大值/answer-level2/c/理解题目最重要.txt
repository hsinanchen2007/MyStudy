### 解题思路
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]

两个输入的含义，第一个组：外层函数调用的动作，第二组：等待操作的数据内容；
输出是每次调用我们函数的返回值。

### 代码

```c
typedef struct {
    int que[10000];
    int begin;
    int end;
    int max;
    int count;
} MaxQueue;


MaxQueue* maxQueueCreate() {
    MaxQueue * queue;
    queue = (MaxQueue*)malloc(sizeof(MaxQueue));
    //memset(queue,0,sizeof(MaxQueue));
    queue->begin = 0;
    queue->end = 0;
    queue->count = 0;
    queue->max = -1;
    return queue;
}

int maxQueueMax_value(MaxQueue* obj) {
    int max = 0;
    if(obj->count == 0){
        return -1;
    }
    if(obj->begin <= obj->end){
        for(int i = obj->begin; i <= obj->end; i++){
            max = max > obj->que[i] ? max:obj->que[i];
        }
    }
    return max;
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    obj->que[obj->end] = value;
    obj->end++;
    obj->count++;
    return;
}

int maxQueuePop_front(MaxQueue* obj) {
    int ret = -1;
    if(obj->count == 0){
        return ret;
    }   
    ret = obj->que[obj->begin];
    obj->begin++;
    obj->count--;
    return ret;
}

void maxQueueFree(MaxQueue* obj) {
    free(obj);
    return;
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