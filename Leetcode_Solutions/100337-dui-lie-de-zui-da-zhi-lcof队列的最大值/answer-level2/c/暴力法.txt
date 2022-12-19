
#define M 10001

typedef struct {
    int q[M];
    int b;
    int e;
} MaxQueue;


MaxQueue* maxQueueCreate() {
    MaxQueue *q = (MaxQueue *)malloc(sizeof(MaxQueue));
    q->b = 0;  // 队列头
    q->b = 0;  // 队列尾
    return q;
}

int maxQueueMax_value(MaxQueue* obj) {
    if (obj->b == obj->e) { // 此时队列中无数据
        return -1;
    }
    int m = obj->q[obj->b];
    for (int i = obj->b + 1; i <= obj->e; i++) {
        m = m > obj->q[i] ? m : obj->q[i];
    }
    return m;
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    obj->q[obj->e] = value;
    obj->e = obj->e + 1;
    return;
}

int maxQueuePop_front(MaxQueue* obj) {
    if (obj->b == obj->e) { // 此时队列中无数据
        return -1;
    }
    int r = obj->q[obj->b];
    obj->b = obj->b + 1;
    return r;
}

void maxQueueFree(MaxQueue* obj) {
    free(obj);
    obj = NULL;
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