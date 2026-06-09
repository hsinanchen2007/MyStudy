### 解题思路
1.定义一个链表节点和一个链表栈：pop操作需要知道倒数第二个元素，所以使用next不能实现，取用last获取前驱元素；
2.出入栈普通思路；
3.查找最小元素要常数时间，那就把查找的遍历放在入栈中，反正入栈是从头到尾遍历的

### 代码

```c
struct Node{
    struct Node *last;
    int val; 
    int min;  
};

typedef struct {
    struct Node *current_node;
} MinStack;


/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj = (MinStack*)malloc(sizeof(MinStack));
    obj->current_node = NULL;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    int min;
    node->val = x;
    if(!(obj->current_node))
    {
        node->last = NULL;
        node->min = x;
    }
    else
    {
        node->last = obj->current_node;
        node->min = (obj->current_node->min < x) ? obj->current_node->min : x;
    }
    obj->current_node =node;
}

void minStackPop(MinStack* obj) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node = obj->current_node;
    obj->current_node = obj->current_node->last;
    free(node);

}

int minStackTop(MinStack* obj) {
    return obj->current_node->val;
}

int minStackGetMin(MinStack* obj) {
    return obj->current_node->min;
}

void minStackFree(MinStack* obj) {
    struct Node* node;
    while(obj->current_node->last != NULL)
    {
        node = obj->current_node;
        obj->current_node = obj->current_node->last;
         free(node);
    }
    free(obj->current_node);
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