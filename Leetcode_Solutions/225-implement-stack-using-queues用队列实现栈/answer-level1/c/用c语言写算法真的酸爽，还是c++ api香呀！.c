### 解题思路
用c语言写算法真的酸爽，还是c++ api香呀！

### 代码

```c
typedef struct my_stack{
    int data;
    struct my_stack *next;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *my = malloc(sizeof(MyStack));
    my->next = NULL;
    return my;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    MyStack *my = malloc(sizeof(MyStack));
    my->data = x;
    my->next = obj->next;
    obj->next = my;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    MyStack *my = obj->next;
    obj->next = obj->next->next;
    int data = my->data;
    free(my);
    return data;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->next->data;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->next == NULL;
}

void myStackFree(MyStack* obj) {
    while(obj != NULL)
    {
        MyStack *my = obj;
        obj = obj->next;
        free(my);
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