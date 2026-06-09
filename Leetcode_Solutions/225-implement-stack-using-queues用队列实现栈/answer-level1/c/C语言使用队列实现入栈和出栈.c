### 解题思路
此处撰写解题思路

1.使用MyStack标记队列中元素个数和队列的头和尾
2.使用ListCell结构体来形成队列

```
typedef struct ListCell {
    int val;
    struct ListCell* next;
} ListCell;

typedef struct {
    int len;
    ListCell* head;
    ListCell* tail;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* myStack = (MyStack*)malloc(sizeof(MyStack));
    myStack->len = 0;
    myStack->head = NULL;
    myStack->tail = NULL;
    return myStack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    ListCell* cell = (ListCell*)malloc(sizeof(ListCell));
    cell->val = x;
    cell->next = NULL;
    if (obj->len == 0) {
        obj->tail = obj->head = cell;
        obj->len = 1;
    } else {
        cell->next = obj->head;
        obj->head = cell;
        obj->len++;
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int val = obj->head->val;
    if (obj->len == 1) {
        free(obj->head);
        obj->head = NULL;
        obj->tail = NULL;
        obj->len = 0;
    } else {
        ListCell* temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
        temp = NULL;
        obj->len--;
    }
    return val;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->head->val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->len == 0;
}

void myStackFree(MyStack* obj) {
    while (obj->head != NULL) {
        ListCell* tmp = obj->head;
        obj->head = obj->head->next;
        free(tmp);
        tmp = NULL;
    }
    obj->tail = NULL;
    obj->len = 0;
}
```
