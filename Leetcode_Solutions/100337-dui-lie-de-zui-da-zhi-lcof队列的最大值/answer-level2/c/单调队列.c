### 解题思路
1. 如果只是入队、出队，则一个数组模拟即可；
2. 要获取最大值，就可以采用单调队列，与https://leetcode-cn.com/problems/sliding-window-maximum/采用类似的方式，本题要采用单调不增队列，如果是单调减队列也是有问题的；
3. maxQueuePush_back接口O(1)如何理解，因为每个数字只能够进入一次队列，所以是O(1)，不能只看while就说明不是O(1)

### 代码

```c
#define MAX_N 110001

typedef struct {
    int front1, rear1;
    int queue1[MAX_N];
    int front2, rear2;
    int queue2[MAX_N];//单调不增队列，队头是最大值
} MaxQueue;

MaxQueue* maxQueueCreate() {
    return (MaxQueue *)calloc(1, sizeof(MaxQueue));
}

int maxQueueMax_value(MaxQueue* obj) {
    if (obj->front2 != obj->rear2) {
        return obj->queue2[obj->front2];
    }
    return -1;
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    obj->queue1[obj->rear1++] = value;

    while (obj->rear2 != obj->front2 && obj->queue2[obj->rear2 - 1] < value) {
        obj->rear2--;
    }
    obj->queue2[obj->rear2++] = value;
}

int maxQueuePop_front(MaxQueue* obj) {
    int val;
    if (obj->front1 == obj->rear1) {
        return -1;
    }
    val = obj->queue1[obj->front1++];
    if (val == obj->queue2[obj->front2]) {
        obj->front2++;
    }

    return val;
}

void maxQueueFree(MaxQueue* obj) {
    free(obj);
}
```