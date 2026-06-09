### 解题思路
就是利用最小栈的方式，其他的大佬这里说的很好，我觉得我这里可取的就是我利用的是单链表，应该是链表里面速度最快的。

当然这道题可以用很多种方式，静态链表，结构体里嵌套数组，双链表都可以。

### 代码

```c
struct node{
    int val;
    struct node *next;//后驱
};

typedef struct {
    struct node *stack;
    struct node *stack_min;//最小栈
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {//创建头结点
    MinStack *minStack=(MinStack*)malloc(sizeof(MinStack));
    minStack->stack=(struct node*)malloc(sizeof(struct node));
    minStack->stack_min=(struct node*)malloc(sizeof(struct node));
    minStack->stack->next=NULL;
    minStack->stack_min->next=NULL;
    minStack->stack->val=-2147483647;
    minStack->stack_min->val=-2147483647;
    return minStack;
}

void minStackPush(MinStack* obj, int x) {
    struct node *Node=(struct node *)malloc(sizeof(struct node));
    struct node *Node_min=(struct node *)malloc(sizeof(struct node));
   
   
       //赋值
    Node_min->val=x;
    Node->val=x;
    if(obj->stack_min->next&&obj->stack_min->next->val<x)//最小栈永远保存最小值
    Node_min->val=obj->stack_min->next->val;

    //插入
    Node->next=obj->stack->next;
    obj->stack->next=Node;
    Node_min->next=obj->stack_min->next;
    obj->stack_min->next=Node_min;
}

void minStackPop(MinStack* obj) {
    struct node *q1= obj->stack->next;
    struct node *q2= obj->stack_min->next;
    
    //删除
    if(obj->stack->next)
{    obj->stack->next=q1->next;
    obj->stack_min->next=q2->next;
    free(q1);free(q2);}
}

int minStackTop(MinStack* obj) {
    if(obj->stack->next)
    return obj->stack->next->val;
    return -obj->stack->val;
}

int minStackGetMin(MinStack* obj) {
    if(obj->stack->next)
    return obj->stack_min->next->val;
    return obj->stack_min->val;
}

void minStackFree(MinStack* obj) {
    while(obj->stack->next)//释放后续结点
    {
        minStackPop(obj);
    }
    //释放头结点
    free(obj->stack);
    free(obj->stack_min);   
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
```