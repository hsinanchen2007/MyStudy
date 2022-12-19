### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
    int data[1024];
    int top;

} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *s=(MyStack *)malloc(sizeof(MyStack));
    s->top=-1;
    return s;

}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->top++;
    obj->data[obj->top]=x;


}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int res;
    res = obj->data[obj->top];
    obj->top--;
    return res;

}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    int *p;
    p=obj->data[obj->top];
    return p;

}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->top==-1)
    return 1;
    else
    return 0;

}

void myStackFree(MyStack* obj) {
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
关于本题 首先是结构体里面定一个足够大的数组，还有一个top指针用来 标识位置。然后是初始化栈，先malloc一块Mystack的空间，然后top指针先定义为-1，再返回。然后是push操作，top指针往上走，到0的位置，存入元素x，然后top指针再往上走指向栈顶。Pop操作，直接定义一个变量用来pop出来，出来后再top往下走。Empty就是直接判断top的位置，如果是-1明显就是empyty的