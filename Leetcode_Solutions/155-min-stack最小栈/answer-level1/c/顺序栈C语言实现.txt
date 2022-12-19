### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
    int min; //存储最小元素
    int top; //栈顶指针
    int *array;
} MinStack;

#define MAXSIZE 10000 
#define EMPTY -1
/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *S = malloc (sizeof(MinStack));
    if (!S) return NULL;
    S -> array  = (int *) malloc (sizeof(int) * MAXSIZE);
    S -> top = -1;
    S -> min = INT_MAX;
    return S;
}

void minStackPush(MinStack* obj, int x) {
    if (obj -> top == MAXSIZE - 1 ) return ;
    else obj->array[++ obj -> top] = x;
    // 每次记录最小的元素。
    obj -> min = obj -> min < x ? obj-> min : x;
}

void minStackPop(MinStack* obj) {
    if (obj -> top == EMPTY) return;
    int x = obj -> array[obj -> top--];
    if (obj -> min < x) return;
    if (obj -> min == x) {
        int min = INT_MAX;
        for(int i = obj -> top;i > EMPTY;i--){
            if( obj-> array[i] < min)
                min = obj -> array[i];   
        }
        obj -> min = min;
    }
}

int minStackTop(MinStack* obj) {
    if (obj -> top == EMPTY) return 0;
    return obj-> array[obj->top];
}


//并能在常数时间内检索到最小元素的栈
int minStackGetMin(MinStack* obj) {
    if (obj -> top == EMPTY) return 0;
    return obj -> min;
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
```