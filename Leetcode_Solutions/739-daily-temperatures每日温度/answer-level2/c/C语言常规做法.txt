用双链表构成栈来解。该解法占用空间较大，未来再更新算法。
以下是最近一次更新的算法，结构体内部减少了一个变量。
```c
typedef struct a{
    int index;
    struct a* next;
    struct a* prev;
} Node;
void createNode(Node** obj, int i){
    Node* node=malloc(sizeof(Node));
    node->index=i;
    node->next=0;
    node->prev=*obj;
    (*obj)->next=node;
    *obj=node;
}
void deleteNode(Node** obj, int* res, int x){
    res[(*obj)->index]=x;
    (*obj)=(*obj)->prev;
    free((*obj)->next);
    (*obj)->next=0;
}

int* dailyTemperatures(int* T, int TSize, int* returnSize){
    *returnSize=TSize;
    int *res=malloc(sizeof(int)*TSize);
    Node* stack=malloc(sizeof(Node));
    stack->index=0;
    stack->next=0;
    stack->prev=0;
    int i=0;
    while(i<TSize){
        while(T[i]>T[stack->index]&&stack->prev)
            deleteNode(&stack, res, i-stack->index);
        createNode(&stack,i);
        i++;
    }
    while(stack->prev)
        deleteNode(&stack, res, 0);
    free(stack);
    return res;
}
```
以下是第一次成功的做法。
```c
typedef struct a{
    int val;
    int index;
    struct a* next;
    struct a* prev;
} Node;
void createNode(Node** obj, int x, int y){
    Node* node=malloc(sizeof(Node));
    node->val=x;
    node->index=y;
    node->next=0;
    node->prev=*obj;
    (*obj)->next=node;
    *obj=node;
}
void deleteNode(Node** obj, int* res, int x){
    res[(*obj)->index]=x;
    (*obj)=(*obj)->prev;
    free((*obj)->next);
    (*obj)->next=0;
}

int* dailyTemperatures(int* T, int TSize, int* returnSize){
    *returnSize=TSize;
    int *res=malloc(sizeof(int)*TSize);
    Node* stack=malloc(sizeof(Node));
    stack->next=0;
    stack->prev=0;
    int i=0;
    while(i<TSize){
        while(T[i]>stack->val&&stack->prev)
            deleteNode(&stack, res, i-stack->index);
        createNode(&stack,T[i],i);
        i++;
    }
    while(stack->prev)
        deleteNode(&stack, res, 0);
    free(stack);
    return res;
}
```
以下是第一次提交的超时做法。
```c
typedef struct a{
    int val;
    int index;
    int days;
    struct a* next;
    struct a* prev;
} Node;
void createNode(Node** obj, int x, int y){
    Node* node=malloc(sizeof(Node));
    node->val=x;
    node->index=y;
    node->days=1;
    node->next=0;
    node->prev=*obj;
    (*obj)->next=node;
    *obj=node;
}
void deleteNode(Node** obj, int* res, int x){
    res[(*obj)->index]=x;
    (*obj)=(*obj)->prev;
    free((*obj)->next);
    (*obj)->next=0;
}

int* dailyTemperatures(int* T, int TSize, int* returnSize){
    *returnSize=TSize;
    int *res=malloc(sizeof(int)*TSize);
    Node* stack=malloc(sizeof(Node));
    stack->next=0;
    stack->prev=0;
    int i=0;
    Node* tmp;
    while(i<TSize){
        while(T[i]>stack->val&&stack->prev)
            deleteNode(&stack, res, stack->days);
        tmp=stack;
        while(tmp->prev){
            tmp->days++;
            tmp=tmp->prev;
        }
        createNode(&stack,T[i],i);
        i++;
    }
    while(stack->prev)
        deleteNode(&stack, res, 0);
    free(stack);
    return res;
}
```