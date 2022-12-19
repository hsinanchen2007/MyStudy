### 解题思路
队列的基本操作，算是个模板操作了，注意分配的MAXLEN，一开始分配1000给小了，leetcode的题目数组长度最多不会超过10000。
### 代码

```c
#define MAXLEN 100000
typedef struct {
    int front;
	int rear;
	int data[MAXLEN];
} MaxQueue;


MaxQueue* maxQueueCreate() {
    MaxQueue *queue = (MaxQueue*)malloc(sizeof(MaxQueue));
	queue->front = -1;
	queue->rear = -1;
	memset(queue->data, 0, sizeof(int) * MAXLEN);
	return queue;
}

int maxQueueMax_value(MaxQueue* obj) {
	int maxVal = obj->data[obj->front];
	for (int i = obj->front; i <= obj->rear; i++){
		maxVal = obj->data[i] > maxVal ? obj->data[i] : maxVal;
	}
	return maxVal;
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    if (obj->front == -1) {
		obj->front = 0;
	}
	obj->rear = (obj->rear + 1) % MAXLEN;
	obj->data[obj->rear] = value;
}

int maxQueuePop_front(MaxQueue* obj) {
	int val = obj->data[obj->front];
    if (obj->front == obj->rear) {
		obj->front = -1;
		obj->rear = -1;
		return val;
	}
	obj->front = (obj->front + 1) % MAXLEN;
	return val;
}

void maxQueueFree(MaxQueue* obj) {
    free(obj);
	obj = NULL;
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