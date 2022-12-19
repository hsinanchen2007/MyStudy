### 解题思路

### 代码

```c
typedef struct MinStack{
    int val;
    struct MinStack *next;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate() {
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj->next = NULL;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    MinStack *p = (MinStack *)malloc(sizeof(MinStack));
    p->next = obj->next;
    p->val = x;
    obj->next = p;
}

void minStackPop(MinStack* obj) {
    MinStack *p = obj->next;
    obj->next = p->next;
    free(p);
}

int minStackTop(MinStack* obj) {
    return obj->next->val;
}

int minStackGetMin(MinStack* obj) {
    MinStack *p = obj->next;
    int min = p->val;
    while (p != NULL)
    {
        if (min > p->val) min = p->val;
        p = p->next;
    }
    return min;
}

void minStackFree(MinStack* obj) {
    MinStack *p = obj->next;
    MinStack *pc;
    while (p != NULL)
    {
        pc = p->next;
        free(p);
        p = pc;
    }
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