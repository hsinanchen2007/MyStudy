### 解题思路
数据使用单向链表存储，每次只需要对表头进行操作，同时维护节点数size，便于判空。

### 代码

```c
typedef struct newListNode {
	int val;
	struct newListNode* next;
}ListNode;

typedef struct {
    ListNode *first;
	int size;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *newStack = (MyStack *)malloc(sizeof(MyStack));
	newStack->size = 0;
	return newStack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    ListNode *new_element = (ListNode *)malloc(sizeof(ListNode));
	new_element->val = x;
	if (obj->size == 0) {
		new_element->next = NULL;
		obj->first = new_element;
		obj->size++;
	} else {
		new_element->next = obj->first;
		obj->first = new_element;
		obj->size++;
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int res = obj->first->val;
	ListNode* temp = obj->first;
	obj->first = obj->first->next;
	obj->size--;
	free(temp);
	return res;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->first->val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->size == 0;
}

void myStackFree(MyStack* obj) {
    while (obj->size != 0) {
		ListNode* temp = obj->first;
		obj->first = obj->first->next;
		obj->size--;
		free(temp);
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