### 解题思路
此处撰写解题思路
使用堆栈，先入后出，O（n）
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define MAX_LEN  100000
typedef struct {
    int val[MAX_LEN];
    int front;
    int tail;
    int size;
}MyStack;

MyStack *CreatMyStack()
{
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    stack->front = 0;
    stack->tail = 0;
    stack->size = 0;
    memset(stack->val, 0, MAX_LEN);

    return stack;
}

void PushMyStack(MyStack *stack, int value)
{
    stack->val[stack->tail] = value;
    stack->tail++;
    stack->size++;
    return;
}

int  PopMyStack(MyStack *stack)
{
    int value;
    if (stack->size > 0) {
        stack->tail--;
        value = stack->val[stack->tail];
    }
    stack->size--;

    return value;
}

void  FreeMyStack(MyStack *stack)
{
    if (stack != NULL) {
        free(stack);
        stack = NULL;
    } 
    return;
}

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* tmpNode = head;
    MyStack *stack = CreatMyStack();
    int value;
    while (tmpNode != NULL) {
        PushMyStack(stack, tmpNode->val);
        tmpNode = tmpNode->next;
    }
    tmpNode = head;
    while (tmpNode != NULL) {
        value = PopMyStack(stack);
        tmpNode->val = value;
        tmpNode = tmpNode->next;
    }

    FreeMyStack(stack);
    
    return head;
}
```