typedef struct LNode {
    int value;
    struct LNode* next;
} NODE;

typedef struct {
    int len;
    NODE* pNode;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->len = 0;
    obj->pNode = NULL;

    return obj; 
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    pNode->value = x;
    pNode->next = obj->pNode;

    obj->pNode = pNode;
    obj->len++;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if (obj->len == 0) {
        return -1;
    }
    int pop = obj->pNode->value;
    NODE* tmp = obj->pNode->next;
    free(obj->pNode);
    obj->pNode = tmp;
    obj->len--;

    return pop;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (obj->len == 0) {
        return -1;
    }

    return obj->pNode->value;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if (obj->len == 0) {
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    int len = obj->len;
    for (int i = 0; i < len; i++) {
        NODE* tmp = obj->pNode->next;
        free(obj->pNode);
        obj->pNode = tmp;
    }
    free(obj);
    obj = NULL;
}