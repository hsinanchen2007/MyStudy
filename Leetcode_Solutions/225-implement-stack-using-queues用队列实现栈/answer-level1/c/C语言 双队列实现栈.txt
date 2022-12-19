

### 代码

```c
typedef struct Node
{
    int val;
    struct Node* next;
}node,*pnode;

typedef struct queue{
    pnode pfront;
    pnode prear;    
} MyStack;


/** Initialize your data structure here. */

MyStack* myStackCreate() {
    pnode phead = (pnode)malloc(sizeof(node));
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->pfront = obj->prear = phead;
    phead->next = NULL;
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    pnode pnew = (pnode)malloc(sizeof(node));
    pnew->val = x;
    pnew->next = NULL;
    obj->prear->next = pnew;
    obj->prear = pnew;
    return;
}
/** 出队返回出队元素*/
int peek(MyStack* obj)
{
    pnode p = obj->pfront->next;
    int val = p->val;
    if(p!=obj->prear)
    {
        obj->pfront->next = p->next;
        free(p);
    }
    else
    {
        free(p);
        obj->prear = obj->pfront;
        obj->pfront->next = NULL;
    }
    return val;
} 

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->pfront == obj->prear)
        return true;
    else
        return false;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    MyStack* obj_new = myStackCreate();
    int x;
    while(obj->pfront->next != obj->prear)
    {
        x = peek(obj);
        myStackPush(obj_new,x);
    }
    x = peek(obj);
    int a;
    while(!myStackEmpty(obj_new))
    {
        a = peek(obj_new);
        myStackPush(obj,a);
    }
    free(obj_new->pfront);
    return x;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    MyStack* obj_new = myStackCreate();
    int x;
    while(!myStackEmpty(obj))
    {
        x = peek(obj);
        myStackPush(obj_new,x);
    }
    int a;
    while(!myStackEmpty(obj_new))
    {
        a = peek(obj_new);
        myStackPush(obj,a);
    }
    free(obj_new->pfront);
    return x;
}



void myStackFree(MyStack* obj) {
    pnode p = obj->pfront->next;
    pnode q;
    while(p !=NULL)
    {  
        q = p;
        p = p->next;
        free(q);
    }
    free(obj->pfront);
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