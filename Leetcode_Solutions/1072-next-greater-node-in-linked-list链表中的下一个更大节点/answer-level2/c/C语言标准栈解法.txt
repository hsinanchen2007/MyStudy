```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 10007
#define EMPTY -1
struct StackNodeT {
    int index;
    int val;
};
typedef struct StackNodeT* StackNode;
struct StackT {
    int size;
    int top;
    StackNode list;
};
typedef struct StackT* Stack;
Stack InitStack(int size)
{
    Stack stack = (Stack)malloc(sizeof(struct StackT));
    stack->size = size;
    stack->top = EMPTY;
    stack->list = (StackNode)malloc(size * sizeof(struct StackNodeT));
    return stack;
}
void PushStack(Stack stack, int index, int val)
{
    int top = ++stack->top;
    stack->list[top].index = index;
    stack->list[top].val = val;
}
int PopStack(Stack stack)
{
    int top = stack->top--;
    return stack->list[top].index;
}
int PeekStack(Stack stack)
{
    return stack->list[stack->top].val;
}
int IsEmpty(Stack stack)
{
    return stack->top == EMPTY;
}
int* nextLargerNodes(struct ListNode* head, int* returnSize){
    Stack stack = InitStack(MAX_SIZE);
    int* ans = (int*)malloc(MAX_SIZE * sizeof(int));
    memset(ans, 0, MAX_SIZE * sizeof(int));
    int curr = 0;
    struct ListNode* ptr = head;
    while (ptr != NULL) {
        while (!IsEmpty(stack) && PeekStack(stack) < ptr->val) {
            int index = PopStack(stack);
            ans[index] = ptr->val;
        }
        PushStack(stack, curr++, ptr->val);
        ptr = ptr->next;
    }
    *returnSize = curr;
    return ans;
}
```
主要是C语言没有栈结构，自己实现个标准栈。主要代码没几行。
