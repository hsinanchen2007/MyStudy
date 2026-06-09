思路：我们定义2个栈空间，rear和front分别作为其中的栈顶指针。我们限定rear栈空间只能进行push也就是入队，而front栈只能进行pop也就是出队以此来用两个栈来模仿队列。
下面的代码关键地方都给予了注释。

```
#define MAXSIZE 300
#define REAR 1
#define FRONT 0

typedef struct CQueue
{
    //设置2个数组，即2个栈空间，分别定义2个宏REAR，FRONT现性的指明。
	int data[2][MAXSIZE];
	int front, rear;
} CQueue;


CQueue* cQueueCreate() {
	
	CQueue* obj = (CQueue*)malloc(sizeof(CQueue));
	if (!obj)
		return NULL;
	memset(obj, 0, sizeof(CQueue));
	obj->rear = obj->front = -1;	//rear和front分别为一个栈空间的栈顶指针,初始化指向栈底。

	return obj;
}

void cQueueAppendTail(CQueue* obj, int value) {
	//判断是否满队
	if (obj->rear == MAXSIZE - 1 || obj->front == MAXSIZE - 1)
		return;

	//如果数据在front栈，则转移数据到rear栈中
	while (obj->front != -1)
	{
		obj->data[REAR][++obj->rear] = obj->data[FRONT][obj->front--];
	}
	obj->data[REAR][++obj->rear] = value;
}

int cQueueDeleteHead(CQueue* obj) {
	if (obj->rear == obj->front)
		return -1;

	//如果数据在rear栈，则转移数据到front栈中
	while (obj->rear != -1)
		obj->data[FRONT][++obj->front] = obj->data[REAR][obj->rear--];

	return obj->data[FRONT][obj->front--];
}

void cQueueFree(CQueue* obj) {
	free(obj);
}

```
