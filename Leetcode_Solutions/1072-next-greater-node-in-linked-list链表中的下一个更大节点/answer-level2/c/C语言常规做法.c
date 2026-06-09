利用双链表构成栈，双链表每个节点需要记录的是index（位置），但该做法占用空间较大，后续再进行更新。
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
    *obj=(*obj)->prev;
    free((*obj)->next);
    (*obj)->next=0;
}

int* nextLargerNodes(struct ListNode* head, int* returnSize){
    int i=0;
    struct ListNode* traverse=head;
    *returnSize=0;
    while(traverse){
        *returnSize=*returnSize+1;
        traverse=traverse->next;
    }
    int* res=malloc(*returnSize * sizeof(int));
    traverse=head;
    Node* stack=malloc(sizeof(Node));
    stack->prev=0;
    while(i<*returnSize){
        res[i]=traverse->val;
        while(stack->prev&&res[stack->index]<traverse->val)
            deleteNode(&stack,res,traverse->val);
        createNode(&stack,i);
        traverse=traverse->next;
        i++;
    }
    while(stack->prev)
        deleteNode(&stack, res, 0);
    free(stack);
    return res;
}
```