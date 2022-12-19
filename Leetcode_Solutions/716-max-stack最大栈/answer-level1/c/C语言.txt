### 解题思路
很普通的方法，时间和空间都不高

### 代码

```c
#define MAX_SIZE 100000
#define MAX(a, b) ((a) > (b) ? (a) : (b))
typedef struct {
    int num[MAX_SIZE];
    int top;
} MaxStack;

/** initialize your data structure here. */

MaxStack* maxStackCreate() {
    MaxStack *maxStack = (MaxStack *)malloc(sizeof(MaxStack));
    memset(maxStack, 0, sizeof(MaxStack));
    maxStack->top = -1;
    return maxStack;
}

void maxStackPush(MaxStack* obj, int x) {
    if (obj->top < -1 || obj->top >= MAX_SIZE) {
        return;
    }
    obj->num[++obj->top] = x;
}

int maxStackPop(MaxStack* obj) {
//    if (obj->top <= -1 || obj->top >= MAX_SIZE) {
//        return;
//    }
    return obj->num[obj->top--];
}

int maxStackTop(MaxStack* obj) {
//    if (obj->top <= -1 || obj->top >= MAX_SIZE) {
//        return;
//    }
    return obj->num[obj->top];
}

int maxStackPeekMax(MaxStack* obj) {
    int max = INT_MIN;
    for (int i = 0; i <= obj->top; i++) {
        max = MAX(max, obj->num[i]);
    }
    return max;
}

int maxStackPopMax(MaxStack* obj) {
    int index;
    int max = maxStackPeekMax(obj);
    for (index = obj->top; index >= 0; index--) {
        if (obj->num[index] == max) {
            break;
        }
    }
    for (int i = index + 1; i <= obj->top; i++) {
        obj->num[i - 1] = obj->num[i];
    }
    obj->top--;
    return max;
}

void maxStackFree(MaxStack* obj) {
    free(obj);
}

/**
 * Your MaxStack struct will be instantiated and called as such:
 * MaxStack* obj = maxStackCreate();
 * maxStackPush(obj, x);
 
 * int param_2 = maxStackPop(obj);
 
 * int param_3 = maxStackTop(obj);
 
 * int param_4 = maxStackPeekMax(obj);
 
 * int param_5 = maxStackPopMax(obj);
 
 * maxStackFree(obj);
*/
```