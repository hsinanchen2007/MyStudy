### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX_LEN 100000

typedef struct {
    int size;
    int *a;
    int top;
    int next;
    int count;
} MovingAverage;

int push(MovingAverage* ma, int val) {
    if (ma->size == 0) {
        return 0;
    }
    if (ma->count < ma->size) {
        *(ma->a + ma->next) = val;
        ma->next++;
        ma->count++;
    } else if (ma->count == ma->size) {
        (ma->top)++;
        *(ma->a + ma->next) = val;
        ma->next++;
    }
    //printf("count:%d  top: %d next:%d val:%d\n", ma->count, ma->top, ma->next, val);
    return 1;

}

/** Initialize your data structure here. */

MovingAverage* movingAverageCreate(int size) {
    MovingAverage *ma = (MovingAverage *)malloc(sizeof(MovingAverage));
    ma->size = size;
    ma->top = 0;
    ma->next = 0;
    ma->count = 0;
    ma->a = (int *)malloc(sizeof(int) * MAX_LEN);
    return ma;
}

double movingAverageNext(MovingAverage* obj, int val) {
    double total = 0;
    double avg = 0;
    int ret = push(obj, val);
    if (ret == 0) {
        avg = 0;
        return avg;
    }
    int now = 0;
    now = obj->top;
    for (int i = 0; i < obj->count; i++) {
        total += *(obj->a + now);
        now++;
    }
    avg = total / obj->count;
    return avg;
}

void movingAverageFree(MovingAverage* obj) {
    obj->size = 0;
    free(obj->a);
    obj->top = 0;
    obj->next = 0;
    obj->count = 0;
    obj = NULL;
    return;
}

```