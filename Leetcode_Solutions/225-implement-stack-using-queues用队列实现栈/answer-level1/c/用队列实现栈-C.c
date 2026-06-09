### 解题思路
此处撰写解题思路
1.栈的特性是先进后出，队列是先进先出。
2.使用两个队列，一个空队列，一个队列存放数据。
3.当我们入队的时候将数据直接放入非空队列，出队的时候讲非空队列中除队尾外的所有元素放到空队列中，再出队尾即可。

### 代码

typedef int DataType;
typedef struct QListNode {
    struct QListNode *next;
    DataType data;
}QNode;
typedef struct Queue {
    QNode *front;
    QNode *rear;
}Queue;

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

/** Initialize your data structure here. */
void QueueInit(Queue* q)
{
	q->front = q->rear = NULL;
}
DataType QueueFront(Queue* q)
{
	if(q->front != NULL) {
        return q->front->data;
    } else {
        return NULL;
    }
}
DataType QueueBack(Queue* q)
{
	if(q->rear != NULL) {
	    return q->rear->data;
    } else {
        return NULL;
    }
}
int QueueEmpty(Queue* q)
{
	return q->front ? 0 : 1;
}
int QueueSize(Queue* q)
{
	assert(q);

	QNode* cur = q->front;
	int count = 0;

	while (cur) {
		count++;
		cur = cur->next;
	}

	return count;
}

void QueuePush(Queue* q, DataType data) {
	assert(q);

	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->data = data;
	node->next = NULL;

	if (q->rear) {
		q->rear->next = node;
		q->rear = node;
	}
	else {
		q->front = q->rear = node;
	}

}
void QueuePop(Queue* q)
{
	assert(q);

	if (NULL == q->front->next) {
		free(q->front);
		q->front = q->rear = NULL;
	} else {
		QNode* next = q->front->next;
		free(q->front);
		q->front = next;
	}
}


void QueueDestroy(Queue* q)
{
	assert(q);

	QNode* cur = q->front;
	while (cur) {
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	q->front = q->rear = NULL;
}
MyStack* myStackCreate() {
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    QueueInit(&stack->q1);
    QueueInit(&stack->q2);
    return stack;
}
/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (0 !=  QueueEmpty(&obj->q1)) {
        QueuePush(&obj->q2, x);
    } else {
        QueuePush(&obj->q1, x);
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    Queue *emptyq = &obj->q2, *noemptyq = &obj->q1;
    DataType target;
    if (0 != QueueEmpty(&obj->q1)) {
        emptyq = &obj->q1;
        noemptyq = &obj->q2;
    }
    while (QueueSize(noemptyq) > 1) {
        QueuePush(emptyq, QueueFront(noemptyq));
        QueuePop(noemptyq);
    }
    target = QueueFront(noemptyq);
    QueuePop(noemptyq);
    return target;
}
/** Get the top element. */
int myStackTop(MyStack* obj) {
    Queue *noemptyq = &obj->q1;
    if (0 != QueueEmpty(&obj->q1)) {
        noemptyq = &obj->q2;
    }
    return QueueBack(noemptyq);
}


/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if (QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2)) {
        return true;
    } else {
        return false;
    }
}

void myStackFree(MyStack* obj) {
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
    obj = NULL;
}