```
typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

typedef struct Queue
{
	QNode* _head;
	QNode* _tail;
}Queue;

//初始化
void QueueInit(Queue* q)
{
	assert(q);
	q->_head = NULL;
	q->_tail = NULL;
}
//队尾入
void QueuePush(Queue* q, QDataType val)
{
	assert(q);
	QNode* New = (QNode*)malloc(sizeof(QNode));
	New->_data = val;
	New->_next = NULL;
	if (q->_tail == NULL)
	{
		q->_head = q->_tail = New;
	}
	else
	{
		q->_tail->_next = New;
		q->_tail = New;
	}
}
//队头出
void QueuePop(Queue* q)
{
	assert(q);
	QNode* cur = q->_head;
	if (q->_head->_next != NULL)
	{
		q->_head = q->_head->_next;
		free(cur);
	}
	else
	{
		free(q->_head);
		q->_head = q->_tail = NULL;
	}


}
//获得队列头部元素
QDataType QueueHead(Queue* q)
{
	assert(q);
	return q->_head->_data;
}
// 获取队列队尾元素 
QDataType QueueTail(Queue* q)
{
	assert(q);

	return q->_tail->_data;
}
//获得队列中有效的元素个数
QDataType QueueSize(Queue* q)
{
	assert(q);
	int count = 0;
	QNode* cur = q->_head;
	while (cur != NULL)
	{
		++count;
		cur = cur->_next;
	}
	return count;
}
//检查队列是否为空(空 - 1  非空 - 0)
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_head == NULL ? 1 : 0;
}
//销毁队列
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->_head;
	while (cur!= NULL)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_head = q->_tail = NULL;
}

typedef struct
{
    Queue Stack1;
    Queue Stack2;
    
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() 
{
    MyStack* p = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&p->Stack1);
    QueueInit(&p->Stack2);
    return p;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {      //1队列用来进数据   2队列用来出数据

        if(!QueueEmpty(&obj->Stack1))
    {
        QueuePush(&obj->Stack1, x);
    }
    else
    {
        QueuePush(&obj->Stack2, x);
    } 
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
       Queue* pemptyQ = &obj->Stack1;
    Queue* pnoemptyQ = &obj->Stack2;
    if(!QueueEmpty(&obj->Stack1))
    {
        pemptyQ =  &obj->Stack2;
        pnoemptyQ =  &obj->Stack1;
    }

    while(QueueSize(pnoemptyQ) > 1)
    {
        QueuePush(pemptyQ, QueueHead(pnoemptyQ));
        QueuePop(pnoemptyQ);
    }

    int top = QueueTail(pnoemptyQ);
    QueuePop(pnoemptyQ);
    return top;
   
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
      if(!QueueEmpty(&obj->Stack1))
    {
        return QueueTail(&obj->Stack1);
    }
    else
    {
        return QueueTail(&obj->Stack2);
    }
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
      return QueueEmpty(&obj->Stack1) && QueueEmpty(&obj->Stack2); 
}

void myStackFree(MyStack* obj) {
    QueueDestroy(&obj->Stack1);
    QueueDestroy(&obj->Stack2);  
    free(obj);
}
```
