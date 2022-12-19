- 方法一
利用双链表构建栈。
```c
typedef struct node{
    int val;
    struct node* next;
    struct node* prev;
} doublyLinkedList;

void createNode(doublyLinkedList** obj, int x){
    doublyLinkedList* node=malloc(sizeof(doublyLinkedList));
    node->prev=*obj;
    node->next=0;
    node->val=x;
    (*obj)->next=node;
    *obj=node;
}

int charToInt(char* str){
    int i,num=0;
    i=str[0]=='-'?1:0;
    while(str[i])
        num=num*10+str[i++]-'0';
    return str[0]=='-'?-1*num:num;
}

int calPoints(char ** ops, int opsSize){
    int i=0,sum=0;
    doublyLinkedList* stack=malloc(sizeof(doublyLinkedList));
    stack->prev=0;
    stack->next=0;
    stack->val=0;
    while(i<opsSize){
        switch(ops[i][0]){
            case 'C':
                stack=stack->prev;
                free(stack->next);
                stack->next=0;
                break;
            case 'D':
                createNode(&stack,2*stack->val);
                break;
            case '+':
                createNode(&stack,stack->prev->val+stack->val);
                break;
            default:
                createNode(&stack,charToInt(ops[i]));
        }
        i++;
    }
    while(stack->prev){
        sum+=stack->val;
        stack=stack->prev;
        free(stack->next);
    }
    free(stack);
    return sum;
}
```
- 方法二
利用数组构建栈。（待更）