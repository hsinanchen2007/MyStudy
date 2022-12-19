使用了循环链表，把队列头部front的next指针指向队尾
（感觉自己跑题了..）


```
struct Node{
    int val;
    struct Node* next;
};

typedef struct {
    struct Node* front;
    struct Node* rear;
    int size;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* obj = ( MyStack*)malloc(sizeof(MyStack));
    obj->front = NULL;
    obj->rear = NULL;
    obj->size = 0;
    return obj;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->size==0)
        return true;
    return false;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = x;
    if(myStackEmpty(obj)){
        obj->front = node;
        obj->rear = node;
        obj->front->next = obj->rear;
    }
    else{
        node->next = obj->rear;
        obj->rear = node;
        obj->front->next = obj->rear;
    }
    obj->size++;
    return;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int x = obj->front->next->val;
    obj->rear = obj->rear->next;
    obj->front->next = obj->rear;
    obj->size--;
    return x;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->rear->val;
}



void myStackFree(MyStack* obj) {
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
