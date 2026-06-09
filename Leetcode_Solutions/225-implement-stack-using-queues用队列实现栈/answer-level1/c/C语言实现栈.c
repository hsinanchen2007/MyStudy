### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
    int *base;
    int *top;
    int cap;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *myStack=(MyStack *)malloc(sizeof(MyStack));
    myStack->base=(int *)malloc(sizeof(int)*10);
    myStack->top=myStack->base;
    myStack->cap=10;
    return myStack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if(obj->top-obj->base>=obj->cap-1){
        obj->base=(int *)realloc(obj->base,sizeof(int)*(obj->cap+10));
        obj->top=obj->base+obj->cap-1;
        obj->cap+=10;
    }
    *(obj->top)=x;
    obj->top++;
    return;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    return *(--obj->top);
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return *(obj->top-1);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return (obj->top==obj->base)?true:false;
}

void myStackFree(MyStack* obj) {
    free(obj->base);
    free(obj);
    return;
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