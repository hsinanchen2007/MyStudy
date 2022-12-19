### 解题思路
带头节点链表，只需判断是否为最后一个节点，或倒数第二个节点就行
### 代码

```c
typedef struct stack{
int data;
struct stack* next;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
MyStack* head=(MyStack*)malloc(sizeof(MyStack));
head->next=NULL;
return head;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
MyStack* temp=obj;
while(temp->next){
    temp=temp->next;
}
temp->next=(MyStack* )malloc(sizeof(MyStack));
temp->next->data=x;
temp->next->next=NULL;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
MyStack * temp=obj;
int data;
if (!temp->next){
    printf("it's empty \n");
}
else{
    while(temp->next->next){
        temp=temp->next;
    }
    MyStack* free_node=temp->next;
    data=temp->next->data;
    temp->next=NULL;
    free(free_node);
}
return data;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
int data;
MyStack* temp=obj;
if (!temp->next){
    printf("empty");
}
else{
    temp=temp->next;
    while(temp->next){
        temp=temp->next;
    }
    data=temp->data;
}
return data;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
MyStack* temp=obj;
bool signal=true;
if (temp->next){
signal=false;
}
return signal;
}

void myStackFree(MyStack* obj) {
    while(obj->next){
    myStackPop(obj);
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