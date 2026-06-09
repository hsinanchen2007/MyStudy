### 解题思路
1.C语言标准库没有队列，因此使用两个链表
2.Push时，现将数据放到不为空的队列，在将另外一个链表挂过来。
3.Pop是直接弹出非空的链表头。
其他的都比较简单直接看代码

### 代码

```c
typedef struct List_ {
    int val;
    struct List *next;
}List;
typedef struct {
    List *list1;
    List *list2;
} MyStack;

/*使用链表模拟，每次将数据放在空链表中，然后将另一个链表中数据放在新链表中*/
/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *obj = malloc(sizeof(MyStack));
    if (obj == NULL){
        return NULL;
    }
    obj->list1 = NULL;
    obj->list2 = NULL;
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (obj == NULL){
        return;
    }
    List *node = malloc(sizeof(List));
    node->val = x;
    node->next = NULL;
    if (obj->list1 == NULL){
        obj->list1 = node;
        node->next = obj->list2;
        obj->list2 = NULL;
    } else {
        obj->list2 = node;
        node->next = obj->list1;
        obj->list1 = NULL;
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    List* head = obj->list1 != NULL ? obj->list1 : obj->list2;
    List* tmp = head;
    head = head->next;
    if (obj->list1) {
        obj->list1 = head;
    } else {
        obj->list2 = head;
    }
    int ans = tmp->val;
    free(tmp);
    return ans;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    List* head = obj->list1 != NULL ? obj->list1 : obj->list2;
    return head->val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->list1 == NULL && obj->list2 == NULL;
}

void myStackFree(MyStack* obj) {
    List* head = obj->list1 != NULL ? obj->list1 : obj->list2;
    while(head){
        List* pre = head;
        head = head->next;
        free(pre);
    }
    free(obj);
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