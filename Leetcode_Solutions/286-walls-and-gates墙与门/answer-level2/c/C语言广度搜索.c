![image.png](https://pic.leetcode-cn.com/a8b40b4485f5b592835fb621f4873690a2a54df2b58291239f5ecf7fceea2889-image.png)

从出口位置开始广度搜索；

```

#define INF 2147483647
#define GATE 0
#define INIT (-1)
#define DIR 4
typedef struct {
    int row;
    int col;
}RoomInfo;
typedef struct {
    int size;
    int head;
    int tail;
    RoomInfo *queue;
}MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if (obj->head == INIT) return true;
	return false;
}
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	if ((obj->tail + 1) % obj->size == obj->head) return true;
	return false;
}
int myCircularQueueSize(MyCircularQueue* obj) {
    if (true == myCircularQueueIsEmpty(obj)) return 0;
    if (true == myCircularQueueIsFull(obj)) return obj->size;
    if (obj->head > obj->tail) {
        return obj->head - obj->tail -1;
    }else {
        return obj->tail - obj->head +1;
    }
}
MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* p = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	p->size = k;
	p->head = INIT;
	p->tail = INIT;
	p->queue = (int *)malloc(sizeof(RoomInfo)*(k+1));
	return p;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, RoomInfo* value) {
	if (true == myCircularQueueIsFull(obj)) return false;
	if (true == myCircularQueueIsEmpty(obj)) {
		obj->head = 0;
	}
	obj->tail = (obj->tail + 1) % obj->size;
	obj->queue[obj->tail].row = value->row;
    obj->queue[obj->tail].col = value->col;
	return true;
}
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (true == myCircularQueueIsEmpty(obj)) return false;
	if (obj->head == obj->tail) {
		obj->head = INIT;
		obj->tail = INIT;
		return true;
	}
	obj->head = (obj->head + 1) % obj->size;
	return true;
}
RoomInfo* myCircularQueueFront(MyCircularQueue* obj) {
	if (true == myCircularQueueIsEmpty(obj)) return NULL;
	return &(obj->queue[obj->head]);
}
RoomInfo* myCircularQueueRear(MyCircularQueue* obj) {
	if (true == myCircularQueueIsEmpty(obj)) return NULL;
	return &(obj->queue[obj->tail]);
}
void myCircularQueueFree(MyCircularQueue* obj) {
	if (obj == NULL) return;
	if (obj->queue != NULL) {
		free(obj->queue);
		obj->queue = NULL;
	}
	free(obj);
	obj = NULL;
}

void wallsAndGates(int** rooms, int roomsSize, int* roomsColSize){
    int m = roomsSize;
    if (m == 0) return;
    //printf("m:%d %d \n",m, *roomsColSize);
    int n = *roomsColSize;
    RoomInfo direction[DIR] = {
        {1,  0},//下
        {-1, 0},//上
        {0,  1},//右
        {0, -1}//左
    };
    //printf("m:%d n:%d\n",m,n);
    
    //队列创建,初始化队列，将门的位置放到队列中
    MyCircularQueue* obj = myCircularQueueCreate(m*n);
    if (obj == NULL) return;
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (rooms[row][col] == GATE) {
                RoomInfo tmp;
                tmp.row = row;
                tmp.col = col;
                myCircularQueueEnQueue(obj, &tmp);
            }
        }
    }
    
    //从队列里面取数据处理，按照4个方向步进分别处理
    while (myCircularQueueIsEmpty(obj) == false) {
        RoomInfo *tmp = myCircularQueueFront(obj);
        myCircularQueueDeQueue(obj);
        for (int i = 0; i < DIR; i++) {
            int r = tmp->row + direction[i].row;
            int c = tmp->col + direction[i].col;
            if (r < 0 || c < 0 || r >= m || c >= n || rooms[r][c] != INF) {
                continue;
            }
            rooms[r][c] = rooms[tmp->row][tmp->col] + 1;
            RoomInfo tmp;
            tmp.row = r;
            tmp.col = c;
            myCircularQueueEnQueue(obj, &tmp);
        }
    }
    //资源释放
    myCircularQueueFree(obj);
}
```
