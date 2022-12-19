### 解题思路
此处撰写解题思路
用一个链表模拟栈，由链表节点数目size和链表头head组成，head始终指向链表的最新节点，相当于指向栈顶。
### 代码


typedef struct node{
    int data;
    struct node * next;
}Node;

typedef struct {
    Node *head;
    int size;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate() {
    MyStack * my = (MyStack *)malloc(sizeof(MyStack));
    my->size = 0;
    my->head = NULL;
    return my;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    Node * tmp = (Node *)malloc(sizeof(Node));
    tmp->data = x;
    tmp->next = obj->head;
    obj->head = tmp;
    obj->size++;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int ret = obj->head->data;
    Node *tmp = obj->head;
    obj->head = obj->head->next;
    free(tmp);
    obj->size--;
    return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return (obj->head->data);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return (obj->size == 0);
}

void myStackFree(MyStack* obj) {
    while(obj->size > 0)
    {
        Node *tmp = obj->head;
        obj->head = obj->head->next;
        free(tmp);
        obj->size--;
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