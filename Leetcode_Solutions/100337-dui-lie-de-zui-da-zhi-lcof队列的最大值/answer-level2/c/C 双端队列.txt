### 解题思路
直接看代码

### 代码

```c
typedef struct deque {
	int front;
	int rear;
	int items;
	int maxSize;
	int *arr;
} Deque;

void initializeDeque (Deque * pq, int maxSize) {
	pq->front = 0;
	pq->rear = -1;
	pq->items = 0;
	pq->maxSize = maxSize;
	pq->arr = (int *)malloc(sizeof(int) * maxSize);
	memset(pq->arr, 0, sizeof(int) * maxSize);
}

bool dequeIsFull (const Deque * pq) {
	if (pq->maxSize == pq->items) {
		return true;
	} else {
		return false;
	}
}

bool dequeIsEmpty (const Deque * pq) {
	return pq->items == 0;
}

int dequeItemCount (const Deque * pq) {
	return pq->items;
}

bool push_back (int item, Deque * pq) {
	if (dequeIsFull(pq)) {
		return false;
	} else {
		pq->rear = (pq->rear + 1) % (pq->maxSize);
		pq->items++;
		pq->arr[pq->rear] = item;
		return true; 
	}
}

bool push_front (int item, Deque * pq) {
	if (dequeIsFull(pq)) {
		return false;
	} else {
		pq->front = (pq->front - 1 + pq->maxSize) % (pq->maxSize);
		pq->items++;
		pq->arr[pq->front] = item;
		return true;
	}
}

bool pop_front(int* pitem, Deque * pq) {
	if (dequeIsEmpty(pq)) {
	   return false;
	}
	*pitem = pq->arr[pq->front];
	pq->front = (pq->front + 1) % (pq->maxSize);
	pq->items--;
	return true; 
}

bool pop_back(int* pitem, Deque * pq) {
	if (dequeIsEmpty(pq)) {
	   return false;
	}
	*pitem = pq->arr[pq->rear];
	pq->rear = (pq->rear - 1 + pq->maxSize) % (pq->maxSize);
	pq->items--;
	return true; 
}

int peek_front (const Deque * pq) {
	if (!dequeIsEmpty(pq)) {
		return pq->arr[pq->front];
	} else {
		return INT_MIN;
	}
}

int peek_back (const Deque * pq) {
	if (!dequeIsEmpty(pq)) {
		return pq->arr[pq->rear];
	} else {
		return INT_MIN;
	}
}

/** initialize your data structure here. */

typedef struct {
	Deque *deque;
	Deque *maxIndexDeque;
} MaxQueue;


MaxQueue* maxQueueCreate() {
	MaxQueue *maxQueue = (MaxQueue *) malloc (sizeof(MaxQueue));
	Deque *deque = (Deque *) malloc (sizeof(Deque));
	initializeDeque(deque, 1024);
	Deque *maxIndexDeque = (Deque *) malloc (sizeof(Deque));
	initializeDeque(maxIndexDeque, 1024);
	maxQueue->deque = deque;
	maxQueue->maxIndexDeque = maxIndexDeque;
	return maxQueue;
}

int maxQueueMax_value(MaxQueue* obj) {
	if (peek_front(obj->maxIndexDeque) >= 0) {
		return obj->deque->arr[peek_front(obj->maxIndexDeque)];
	} else {
		return -1;
	}
}

void maxQueuePush_back(MaxQueue* obj, int value) {
	while (!dequeIsEmpty(obj->maxIndexDeque) && obj->deque->arr[peek_back(obj->maxIndexDeque)] < value) {
		int i = 0;
		pop_back(&i, obj->maxIndexDeque);
	}
	if (!dequeIsFull(obj->deque)) {
		push_back(value, obj->deque);
	}
	if (!dequeIsFull(obj->maxIndexDeque)) {
		push_back((obj->deque->rear) % obj->deque->maxSize, obj->maxIndexDeque);
	}
}

int maxQueuePop_front(MaxQueue* obj) {
	if (peek_front(obj->maxIndexDeque) == obj->deque->front) {
		int i = 0;
		pop_front(&i, obj->maxIndexDeque);
	}
	int x = -1;
	if (!dequeIsEmpty(obj->deque)) {
		pop_front(&x, obj->deque);
	}
	return x;
}

void maxQueueFree(MaxQueue* obj) {    
	free(obj->deque->arr);
	free(obj->maxIndexDeque->arr);
	free(obj->deque);
	free(obj->maxIndexDeque);
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