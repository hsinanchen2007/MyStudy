利用双链表，构建两个栈。
为了简短易读，构建了创建节点和删除结点的函数。
```c
typedef struct node{
    int val;
    struct node* next;
    struct node* prev;
} doublyLinkedList;

typedef struct {
    doublyLinkedList* stack;
    doublyLinkedList* min;
} MinStack;

//doublyLinkedListCreate()创建的是双链表的头节点。
doublyLinkedList* doublyLinkedListCreate(){
    doublyLinkedList* node=malloc(sizeof(doublyLinkedList));
    node->next=0;
    node->prev=0;
    node->val=2147483647;
    return node;
}

MinStack* minStackCreate(){
    MinStack* obj=malloc(sizeof(MinStack));
    obj->stack=doublyLinkedListCreate();
    obj->min=doublyLinkedListCreate();
    return obj;
}

//createNode()创建的是栈元素。
void createNode(doublyLinkedList* obj, int x){
    doublyLinkedList* node=malloc(sizeof(doublyLinkedList));
    node->next=0;
    node->prev=obj;
    node->val=x;
    obj->next=node;
}

void deleteNode(doublyLinkedList** obj){
    //注意二级指针。
    *obj=(*obj)->prev;
    free((*obj)->next);
    (*obj)->next=0;
}

void minStackPush(MinStack* obj, int x) {
    createNode(obj->stack, x);
    obj->stack=obj->stack->next;
    if(x<=obj->min->val){
        createNode(obj->min, x);
        obj->min=obj->min->next;
    }
}

void minStackPop(MinStack* obj) {
    if(obj->min->val==obj->stack->val) deleteNode(&(obj->min));
    deleteNode(&(obj->stack));
}

int minStackTop(MinStack* obj) {
    return obj->stack->val;
}

int minStackGetMin(MinStack* obj) {
    return obj->min->val;
}

void minStackFree(MinStack* obj) {
    while(obj->stack->prev) minStackPop(obj);
    free(obj->stack);
    free(obj->min);
    free(obj);
}
```