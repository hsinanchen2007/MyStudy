typedef struct MyStack {
    int val;
    struct MyStack *next;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *head;
    head = (MyStack *)malloc(sizeof(MyStack));
    head->next = NULL;
    return head;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    MyStack * newHead;
    newHead = (MyStack *)malloc(sizeof(MyStack));
    newHead->next = obj->next;
    newHead->val = x;
    obj->next = newHead;
    return;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int result;
    MyStack * head;
    head = obj->next;
    result = head->val;
    obj->next = head->next;
    free(head);
    return result;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->next->val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->next == NULL) {
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    MyStack *node;
    MyStack *temp;
    if (obj->next == NULL) {
        return;
    }
    node = obj->next;
    while(node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

