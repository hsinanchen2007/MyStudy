### 解题思路
题目的难点在于把问题转化为循环队列。转化成循环队列之后，要注意队列满了的情况，此时需要处理头指针。另外，队列不满的时候，求平均的份数等于队列中不为空的元素的个数，而不是一直都等于队列的长度。

### 代码

```c
typedef struct {
    int *data;
    int head;
    int tail;
    int capacity;
} MovingAverage;

/** Initialize your data structure here. */

MovingAverage* movingAverageCreate(int size) {
    MovingAverage* q = (MovingAverage*)malloc(sizeof(MovingAverage));
    q->data = (int*)malloc(sizeof(int) * (size+1));
    q->head = 0;
    q->tail = 0;
    q->capacity = size + 1;
    for(int i = 0; i < size; i++){
        q->data[i] = 0;
    }
    return q;
}

double movingAverageNext(MovingAverage* obj, int val) {
    if(obj->head == ((obj->tail + 1) % obj->capacity)){
        obj->data[obj->tail] = val;
        obj->head = (obj->head + 1) % obj->capacity;
        obj->tail = (obj->tail + 1) % obj->capacity;
    }
    else{
        obj->data[obj->tail] = val;
        obj->tail = (obj->tail + 1) % obj->capacity;
    }
    double ave = 0;
    int size = (obj->tail - obj->head + obj->capacity) % obj->capacity;
    int i = obj->head;
    int j = size;
    while(j){
        ave += obj->data[i];
        i = (i + 1) % obj->capacity;
        j--;
    }
    return ave/size;
}

void movingAverageFree(MovingAverage* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);
 
 * movingAverageFree(obj);
*/
```