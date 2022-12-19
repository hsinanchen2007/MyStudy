**解题思路**：
    结构体成员`size`记录栈的大小，`top`记录栈顶，`stack`用来记录动态分配给栈的内存块。
    若目前栈的大小等于栈顶，即`obj->size==obj->top`，则使用`realloc`动态扩存。

```
#define NUM 100

typedef struct {
    int top;
    int size;
    int* stack;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* ans=(MyStack*)malloc(sizeof(MyStack));
    ans->top=0;
    ans->stack=(int*)malloc(sizeof(int)*NUM);
    ans->size=NUM;
    return ans;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if(obj->top==obj->size){
        obj->stack=(int*)realloc(obj->stack,obj->size*2);
        obj->size=2*(obj->size);
    }
    (obj->stack)[obj->top]=x;
    obj->top=obj->top+1;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if(obj->top==0){
        return -1;
    }
    obj->top=obj->top-1;
    return (obj->stack)[obj->top];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if(obj->top==0){
        return -1;
    }
    return (obj->stack)[obj->top-1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->top==0){
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj->stack);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
```
