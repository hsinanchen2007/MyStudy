typedef struct {
    int data[1000];
    int top;
} MinStack;
//int min = 0;
/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *s = NULL;
    s = (MinStack *)malloc(sizeof(MinStack));
    s->top = -1;
    return s;
}

void minStackPush(MinStack* obj, int x) {
    if(obj->top+1 < 1000)
    {
        obj->top++;
        obj->data[obj->top] = x;
    }
}

void minStackPop(MinStack* obj) {
    if(obj->top > -1)
    {
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    if(obj->top > -1)
    {
        return obj->data[obj->top];
    }

    return;
}

int minStackGetMin(MinStack* obj) {
    if(obj->top > -1)
    {
        int min = 0;
        int temp;
        for(int i = 0; i <= obj->top; i++)
        {
            if(obj->data[min] > obj->data[i])
            {
                min = i;
                temp = obj->data[i];
                obj->data[i] = obj->data[min];
                obj->data[min] = temp;
            }
        }
        return obj->data[min];
    }
    return;
   //return obj->data[min];
}

void minStackFree(MinStack* obj) {
    free(obj);
}
