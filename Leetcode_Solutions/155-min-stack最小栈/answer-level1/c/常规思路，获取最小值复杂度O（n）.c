### 解题思路
此处撰写解题思路

### 代码

```c
#define  MIXSIZE 2000
typedef struct {
    int *e;
    int top;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj=(MinStack *)malloc(sizeof(MinStack));
    obj->e=(int *)malloc(MIXSIZE*sizeof(int));
    obj->top=-1;
    return obj;
}
void minStackPush(MinStack* obj, int x) {
    if(obj->top==MIXSIZE-1){

    }else{
		int top=obj->top;
        obj->e[++top]=x;
        obj->top=top;
    }
    
}
void minStackPop(MinStack* obj) {
    //obj->e[obj->top--];
    if(obj->top==-1){

    }else{
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    if(obj->top==-1){
        return 0;
    }else{
        return obj->e[obj->top];
    }
}

int minStackGetMin(MinStack* obj) {
    if(obj->top==-1){
        return 0;
    }
    int min=obj->e[obj->top];
    for(int i=obj->top;i>-1;i--){
        if(min>obj->e[i]){
            min=obj->e[i];
        }
    }
    return min;
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