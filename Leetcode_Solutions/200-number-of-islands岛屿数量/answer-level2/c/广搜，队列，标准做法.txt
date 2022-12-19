![image.png](https://pic.leetcode-cn.com/60b382c36b37ac963599f32c8bb602d9edad111502de740a3e17defb1d48470c-image.png)
`#define DIR 4
#define WATER '0' 
#define LAND  '1'
#define INIT (-1)
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
MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* p = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	p->size = k;
	p->head = INIT;
	p->tail = INIT;
	p->queue = (RoomInfo *)malloc(sizeof(RoomInfo)*(k+1));
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
int myCircularQueueSize(MyCircularQueue* obj) {
    if (true == myCircularQueueIsEmpty(obj)) return 0;
    if (true == myCircularQueueIsFull(obj)) return obj->size;
    if (obj->head > obj->tail) {
        return obj->head - obj->tail -1;
    }else {
        return obj->tail - obj->head +1;
    }
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

void findland(char** grid, int m, int n, MyCircularQueue* obj) {
    RoomInfo direction[DIR] = {
        {1,  0},//下
        {-1, 0},//上
        {0,  1},//右
        {0, -1}//左
    };
    while (myCircularQueueIsEmpty(obj) != true) {
        RoomInfo* p = myCircularQueueFront(obj);
        RoomInfo info;
        info.row = p->row;
        info.col = p->col;
        myCircularQueueDeQueue(obj);
        
        for (int i = 0; i < DIR; i++) {
            int r = info.row + direction[i].row;
            int c = info.col + direction[i].col;
            if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == WATER) {
                continue;
            }
            RoomInfo tmp;
            tmp.row = r;
            tmp.col = c;
            myCircularQueueEnQueue(obj, &tmp);
            grid[r][c] = WATER;
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int m = gridSize;
    if (m == 0) return 0;
    int n = *gridColSize;
    int rst = 0;
    
    MyCircularQueue* obj = myCircularQueueCreate(m*n);
    
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (grid[row][col] == LAND) {
                rst++;
                RoomInfo tmp;
                tmp.row = row;
                tmp.col = col;
                myCircularQueueEnQueue(obj, &tmp);
                grid[row][col] = WATER;
                findland(grid, m, n, obj);
            }
        }
    }    
    myCircularQueueFree(obj);
    return rst;
}`