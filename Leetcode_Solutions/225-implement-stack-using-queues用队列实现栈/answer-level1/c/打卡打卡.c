### 解题思路
没有边界检查的数组
![image.png](https://pic.leetcode-cn.com/cde1d8163fb116de6829e111b10ebbe5d42e9efe2ac3020849c5c8342082c621-image.png)
![image.png](https://pic.leetcode-cn.com/92359d01d985b48e4366be40a5527b84cf336bbec7542f0acf4a70aa5dce9d45-image.png)

### 代码

```c
#define QUEUESIZE 10000
typedef struct {
    int data[QUEUESIZE];
    int front;
    int rear;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
   MyStack* stack = malloc(sizeof(MyStack));
   memset(stack, 0, sizeof(MyStack));
   stack->front = 0;
   stack->rear  = 0;
   return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->front++;
    obj->data[obj->front]=x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {    
    int a = obj->data[obj->front];
    obj->front--;
    return a;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->data[obj->front];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->front == obj->rear) {
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj);
    obj = NULL;
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