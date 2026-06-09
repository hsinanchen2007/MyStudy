### 解题思路
数组模拟队列实现
注意元素最多有3001
注意边界值
溢出，假性溢出等常见问题。

### 代码

```c
#define MAXSIZE 3001
#define ERR 1
#define OK 0

typedef struct {
    int * array;
    int * head;
    int * tail;
    int cnt;
    int size;
} RecentCounter;

bool isEmpty(RecentCounter * recentCounter) 
{
    if (recentCounter->cnt == 0) {
        return true;
    }
    return false;
}

bool isFull(RecentCounter * recentCounter) 
{
    if (recentCounter->cnt == recentCounter->size) {
        return true;
    }
    return false;
}

int insertTail(RecentCounter * recentCounter, int item)
{
    //如果队列已经满了，不允许再插入元素。
    if (isFull(recentCounter)) {
        return ERR;
    }
    *(recentCounter->tail) = item;
    //如果tail已经到最后，需要把指针指向数组开始
    if(recentCounter->tail == (recentCounter->array + MAXSIZE - 1)) {
        recentCounter->tail = recentCounter->array;
    }else {
            recentCounter->tail++;
    }
    recentCounter->cnt++;
    //插入时，好像不会假性溢出
    if ((0 == recentCounter->cnt) 
        && (recentCounter->head == recentCounter->tail)) {
            recentCounter->head = recentCounter->array;
            recentCounter->tail = recentCounter->array;
    }
    return OK;
}

int pollHead(RecentCounter * recentCounter)
{
    if (isEmpty(recentCounter)) {
        return ERR;
    } 
    //如果head已经到最后，需要把指针指向数组开始
    if(recentCounter->head == (recentCounter->array + MAXSIZE - 1)) {
        recentCounter->head = recentCounter->array;
    }else {
        recentCounter->head++;
    }

    recentCounter->cnt--;
    //如果弹出时出现，出现假性溢出
    if ((0 == recentCounter->cnt) 
        && (recentCounter->head == recentCounter->tail)) {
            recentCounter->head = recentCounter->array;
            recentCounter->tail = recentCounter->array;
    }
    return OK;
}

RecentCounter* recentCounterCreate() {
    RecentCounter * recentCounter = (RecentCounter *)malloc(sizeof(RecentCounter));
    memset(recentCounter, 0, sizeof(RecentCounter));
    recentCounter->array = (int *)malloc(sizeof(int) * MAXSIZE);
    memset(recentCounter->array, 0, sizeof(int) * MAXSIZE);
    recentCounter->head = recentCounter->array;
    recentCounter->tail= recentCounter->array;
    recentCounter->cnt = 0;
    recentCounter->size = MAXSIZE;
    return recentCounter;
}  

int recentCounterPing(RecentCounter* obj, int t) {
    if (NULL == obj) {
        return 0;  
    }
    while (true != isEmpty(obj)) {
        //检查是否应该出队列
        if ((t - 3000) > *(obj->head)) {
           pollHead(obj);
        }else {
            break;
        }
    }
    //新的元素入队列
    if (isFull(obj)) {
        return MAXSIZE;
    } else {
        insertTail(obj, t);
    }
    return obj->cnt;
}

void recentCounterFree(RecentCounter* obj) {
    if (NULL == obj) {
        return;
    }
    free(obj->array);
    free(obj);
    return;
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/
```