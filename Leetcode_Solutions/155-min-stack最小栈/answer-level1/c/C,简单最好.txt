#define MIN(x,y) ((x<y)?x:y)

typedef struct {
    int *data;
    int top;
    int min;
    int size;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj->data = (int *)malloc(10000*sizeof(int));
    obj->top = -1;
    obj->min = 0x7fffffff;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    obj->top++;
    obj->data[obj->top] = x;
    obj->min = MIN(x,obj->min);
}

void minStackPop(MinStack* obj) {
    int i;
    obj->top--;
    if(obj->min == obj->data[obj->top+1]) {
        obj->min = 0x7fffffff;
        for(i=0; i<=(obj->top); i++) {
            obj->min = MIN(obj->data[i], obj->min);
        }
    }
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    free(obj->data);
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