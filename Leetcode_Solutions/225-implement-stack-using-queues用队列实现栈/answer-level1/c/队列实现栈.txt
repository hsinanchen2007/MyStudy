### 解题思路
1.实现队列
2.利用两个队列实现栈

### 代码

```c
//利用两个队列实现栈。
//一个始终为空，另一个存入元素。
//元素入栈。可以实现为元素入队列。
//当栈顶元素需要移除时，通过把该元素的队列前面的节点全部入另一个队列，即可实现元素出栈与获取。
//栈为空，判断当两个队列均为空时即栈为空。

//1.先实现出队列
// 链式结构：表示队列 
typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;
// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->_rear = q->_front = NULL;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode * newnode = (QNode*)malloc(sizeof(QNode));
	newnode->_data = data;
	newnode->_next = NULL;
	if (q->_rear == NULL)
		q->_front = q->_rear = newnode;
	else
	{
		q->_rear->_next = newnode;
		q->_rear = newnode;
	}
}
// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front->_next == NULL)//只有队头一个节点
	{
		free(q->_front);
		q->_front = q->_rear = NULL;
	}
	else
	{
		QNode* next = q->_front->_next;//新的队头
		free(q->_front);
		q->_front = next;
	}
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);

	return q->_rear->_data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	int n = 0;
	QNode * cur = q->_front;
	while (cur)
	{
		n++;
		cur = cur->_next;
	}
	return n;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	return q->_front == NULL ? 1 : 0;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	QNode* cur = q->_front;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}
//2.利用队列实现栈
typedef struct {
    Queue _q1;//两个队列
    Queue _q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* st=(MyStack*)malloc(sizeof(MyStack));//创建栈
    QueueInit(&st->_q1);//初始化实现栈的两个队列。取地址传指针对队列的数据进行操作
    QueueInit(&st->_q2);
    return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
  //由于实现栈的两个队列需要一个始终是空，故先判断空
  if(!QueueEmpty(&obj->_q1))//如果栈的q1队列不是空的，那么把数据添加进q1队列
  {
    QueuePush(&obj->_q1, x); 
  }
  else
  {
    QueuePush(&obj->_q2, x); 
  }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    Queue* pemptyQ = &obj->_q1;//默认q1队列是空的，q2非空
    Queue* pnoemptyQ = &obj->_q2;
    if(!QueueEmpty(&obj->_q1))//如果q1队列非空，把q2标记为空队列
    {
        pemptyQ =  &obj->_q2;
        pnoemptyQ =  &obj->_q1;
    }

    while(QueueSize(pnoemptyQ) > 1)//非空队列的队列大小大于1时，才能保证只剩下最后一个需要出栈的元素。最后把该元素进行出栈操作
    {
        QueuePush(pemptyQ, QueueFront(pnoemptyQ));//把非空队列的元素拿出来，放入空队列里面
        QueuePop(pnoemptyQ);//把非空队列的拿出来的元素在队列中进行移除！
    }

    int top = QueueBack(pnoemptyQ);
    QueuePop(pnoemptyQ);
    return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
  if(!QueueEmpty(&obj->_q1))//由于只有一个队列是空的，因此返回非空队列的尾的元素即可
    {
        return QueueBack(&obj->_q1);
    }
    else
    {
        return QueueBack(&obj->_q2);
    }
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
  return QueueEmpty(&obj->_q1) && QueueEmpty(&obj->_q2); //如果两个队列均为空，那么栈为空
}

void myStackFree(MyStack* obj) {
    QueueDestroy(&obj->_q1);//先销毁队列
    QueueDestroy(&obj->_q2);

    free(obj);//再释放开辟的栈空间
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
```