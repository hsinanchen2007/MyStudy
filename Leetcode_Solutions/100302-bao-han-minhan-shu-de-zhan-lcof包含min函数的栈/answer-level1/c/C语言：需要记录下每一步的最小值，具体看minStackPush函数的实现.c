比较tricky的地方就是，需要记录下每一步的最小值，具体看minStackPush函数的实现
```
#define MAX_NUM 20001

typedef struct {
    int index;
    int stackValues[MAX_NUM];
    int minStackValues[MAX_NUM];
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* res = (MinStack*)malloc(sizeof(MinStack));

    if (res == NULL) {
        return res;
    }
    res->index = 0;

    return res;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->index == 0) {
        obj->stackValues[obj->index] = x;
        obj->minStackValues[obj->index] = x;
    } else {
        obj->stackValues[obj->index] = x;
        obj->minStackValues[obj->index] =
            obj->minStackValues[obj->index - 1] > x ? x : obj->minStackValues[obj->index - 1];
    }

    obj->index++;
}

void minStackPop(MinStack* obj) {
    obj->index--;

}

int minStackTop(MinStack* obj) {
    return obj->stackValues[obj->index - 1];
}

int minStackMin(MinStack* obj) {
    return obj->minStackValues[obj->index - 1];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

```
![image.png](https://pic.leetcode-cn.com/89ec8893208182cd843fe729973aa2e31ad14a083244854e2713f481375ccc9c-image.png)
