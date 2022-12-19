### 解题思路
为了过关先用链表堆栈实现了，因为还没用过c里面的队列，也不知道怎么用队列实现T T

### 代码

```c
typedef struct STACK_NODE{
    int value;
    struct STACK_NODE *next;
}StackNode;

typedef struct {
    StackNode *stacktop;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *ms;
    ms=(MyStack *)malloc(sizeof(MyStack));
    ms->stacktop=NULL;
    return ms;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    StackNode *new_node;
    new_node=(StackNode *)malloc(sizeof(StackNode));
    new_node->value=x;
    new_node->next=obj->stacktop;
    obj->stacktop=new_node;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int v=obj->stacktop->value;
    StackNode *temp=obj->stacktop;
    obj->stacktop=obj->stacktop->next;
    free(temp);
    return v;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->stacktop->value;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->stacktop == NULL;
}

void myStackFree(MyStack* obj) {
    //StackNode *temp=obj->stacktop;
    while(!myStackEmpty(obj))
    {
        myStackPop(obj);
    }
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