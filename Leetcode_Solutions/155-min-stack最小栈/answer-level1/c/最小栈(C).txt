### 解题思路
用单链表实现链栈，用一个变量min_val保存栈中元素的最小值，每次入栈出栈时比较更新min_val即可。

### 代码

```c
typedef struct tagNode{
    int val;
    struct tagNode *next;
}LinkList, *Node_ptr;

typedef struct {
    LinkList* stk;
    int min_val;
} MinStack;


MinStack* minStackCreate() {
    MinStack *p = (MinStack*)malloc(sizeof(MinStack));
    p->stk = (LinkList*)malloc(sizeof(LinkList));
    p->stk->next = NULL;
    return p;
}

void minStackPush(MinStack* obj, int x) {
    if(!obj->stk->next || (obj->stk->next && x < obj->min_val))
        obj->min_val = x;

    Node_ptr p = (Node_ptr)malloc(sizeof(LinkList));
    p->val = x;
    p->next = obj->stk->next;
    obj->stk->next = p;
}

void findMinVal(MinStack *obj)　　//遍历链表找最小值节点
{
    Node_ptr p = obj->stk->next;
    if(p){
        obj->min_val = p->val;
        while(p){
            if(p->val < obj->min_val)
                obj->min_val = p->val;
            p = p->next;
        }
    }
}

void minStackPop(MinStack* obj) {
    if(obj->stk->next){
        Node_ptr p = obj->stk->next;
        obj->stk->next = p->next;
        if(p->val == obj->min_val){   //若要pop的节点为最小值节点，需要找到新的最小值节点
            findMinVal(obj);
        }
        free(p);
        p = NULL;
    }
}

int minStackTop(MinStack* obj) {
    if(obj->stk->next){
        return obj->stk->next->val;
    }
    return -1;
}

int minStackGetMin(MinStack* obj) {
    if(obj->stk->next){
        return obj->min_val;
    }
    return -1;
}

void minStackFree(MinStack* obj) {
    free(obj);
    obj = NULL;
}
