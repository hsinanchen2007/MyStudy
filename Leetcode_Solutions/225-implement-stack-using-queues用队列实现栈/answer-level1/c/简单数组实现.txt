#define MAX 1024

typedef struct {
    int head;
    int tail;
    int arr[MAX];
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    obj->head = 0;
    obj->tail = 0;
    memset(obj->arr, 0, sizeof(int) *MAX);
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->arr[obj->tail] = x;
    obj->tail++;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    obj->tail--;
    return obj->arr[obj->tail];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->arr[obj->tail - 1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->tail != 0) {
        return false;
    } else {
        return true;
    }
}

void myStackFree(MyStack* obj) {
    if(obj != NULL) {
        free(obj);
    }
}
