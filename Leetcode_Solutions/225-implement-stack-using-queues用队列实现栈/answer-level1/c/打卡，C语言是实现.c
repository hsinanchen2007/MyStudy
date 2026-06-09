
#define MAXSIZE 1024

typedef struct {
  int x;
} MyStack;

int top = 0;
/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *queue = (MyStack*)malloc(sizeof(MyStack)*MAXSIZE);
    memset(queue, 0, sizeof(MyStack)*MAXSIZE);
    top = 0;
    return queue;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj[top].x = x;
    top++;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int tmp = 0;
    if(top >= 1) {
        tmp = obj[top - 1].x;
        obj[top - 1].x = 0;
        top--;  
    }
    return tmp;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj[top - 1].x;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(top == 0) {
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    if(NULL != obj) {
        free(obj);
        top = 0;
    }
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

