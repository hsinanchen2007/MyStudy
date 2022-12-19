### 解题思路
建立一个队列
入栈操作=入队操作
出栈操作=依次让元素出队列，入到新队列中。最后一个元素出队之后作为出栈函数的返回值，不入新队。用新队替换旧队列。
栈顶操作=同出栈操作，只不过最后一个元素入新队。
判断栈空=判断队列空

队列自己写，申请堆内存+int head+int rear组成，申请堆内存的好处是可以动态更改队列容量。
入队：rear=(rear+1)%size; queue[rear]=newValue;
出队：head=(head+1)%size; newValue=queue[head];
队满：(rear+1)%size==head;
队空：head==rear;
初试状态 head=rear=0;首次入队操作是从queue[1]开始装元素。

注意：C 不能用 new 和 delete 运算符，用 malloc()和free()替代
### 代码

```c
typedef struct {
	int size;
	int *queue;
	int head, rear;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
	stack->size = 1;
	stack->queue = (int*)malloc(sizeof(int)*stack->size);
	stack->head = 0;
	stack->rear = 0;
	return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
//如果容量不够，扩容一倍
	if ((obj->rear + 1) % obj->size == obj->head)
	{
		int newSize = obj->size * 2;
		int *newQueue = (int*)malloc(sizeof(int)*newSize);
		int i = 0;
//把旧队列的元素移到新分配的内存段中
		while (obj->head != obj->rear)
		{
			obj->head = (obj->head + 1) % obj->size;
			newQueue[++i] = obj->queue[obj->head];
		}
//更新队列
		obj->size = newSize;
		free(obj->queue);
		obj->queue = newQueue;
		obj->head = 0;
		obj->rear = i+1;
//把元素入到新队列中
		obj->queue[obj->rear] = x;
	}
//容量够，入队
	else
	{
		obj->rear = (obj->rear + 1) % obj->size;
		obj->queue[obj->rear] = x;
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
//新生成一个队列，和旧队列同样大小
	int *newQueue = (int*)malloc(sizeof(int)*obj->size);
//把旧队列的元素出栈、出栈的元素入新队列
	int i = 0;
	while ((obj->head + 1) % obj->size != obj->rear)
	{	
		obj->head = (obj->head + 1) % obj->size;
		newQueue[++i] = obj->queue[obj->head];
	}
//旧队列最后出队的元素就是最新“入栈”的元素，也就是要POP的元素
	obj->head = (obj->head + 1) % obj->size;
	int result = obj->queue[obj->head];
//新队列替换旧队列
	free(obj->queue);
	obj->queue = newQueue;
	obj->head = 0;
	obj->rear = i;
	return result;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
//判断一下是不是一个“空栈”，根据题目要求，其实没必要
	//if (obj->head == obj->rear)
		//return (int)(((unsigned)(~0)) >> 1);

	int *newQueue = (int*)malloc(sizeof(int)*obj->size);

	int i = 0;
	while ((obj->head + 1) % obj->size != obj->rear)
	{
		obj->head = (obj->head + 1) % obj->size;
		newQueue[++i] = obj->queue[obj->head];
	}

	obj->head = (obj->head + 1) % obj->size;
	int result = obj->queue[obj->head];
//最后一个出队的元素是要入新队列的，这里和POP不同
	newQueue[++i] = result;

	free(obj->queue);
	obj->queue = newQueue;
	obj->head = 0;
	obj->rear = i;
	return result;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return obj->head == obj->rear ? 1 : 0;
}

void myStackFree(MyStack* obj) {
	free(obj->queue);
}
```