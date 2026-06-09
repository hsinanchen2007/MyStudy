typedef struct {
    int data[1000];
    int top;
    int min[1000];
} MinStack;
int flag=0;
MinStack* minStackCreate() {
    MinStack* obj=(MinStack*)malloc(sizeof(MinStack));
    obj->top=-1;
    return obj;
}
void minStackPush(MinStack* obj, int x) {
    if(obj->top+1<1000){
        long min;
        if(obj->top==-1){
            min=2147483649;
        }else{
            min=obj->min[obj->top];
        }
        obj->top++;
        obj->data[obj->top]=x;
        if(x<min){
            obj->min[obj->top]=x;
        }else{
            obj->min[obj->top]=min;
        }
    }
}

void minStackPop(MinStack* obj) {
    if(obj->top>-1){
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    if(obj->top>-1){
        return obj->data[obj->top];
    }
    return;
}

int minStackGetMin(MinStack* obj) {
    if(obj->top>-1){
        return obj->min[obj->top];
    }
    return;
}

void minStackFree(MinStack* obj) {
    free(obj);
}
