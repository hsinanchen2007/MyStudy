
### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct Node
{
    struct TreeNode* val;
    struct Node* next;
}node,*pnode;

typedef struct Stack
{
    pnode pbase;
    pnode ptop;
}stack,*pstack;

pstack init_stack() // 初始化栈
{
    pstack ps = (pstack)malloc(sizeof(stack));
    pnode phead = (pnode)malloc(sizeof(node));
    phead->next = NULL;
    ps->pbase = ps->ptop = phead;
    return ps;
}

void push(pstack ps,struct TreeNode* p) // 入栈
{
    pnode pnew = (pnode)malloc(sizeof(node));
    pnew->val = p;
    pnew->next = ps->ptop;
    ps->ptop = pnew;
    return;
}

struct TreeNode* pop(pstack ps) // 出栈 ，返回出栈元素
{
    struct TreeNode* p = ps->ptop->val;
    pnode q = ps->ptop->next;
    free(ps->ptop);
    ps->ptop = q;
    return p;
}

bool is_empty(pstack ps) // 栈是否为空
{
    if(ps->ptop == ps->pbase)
        return true;
    else
        return false;
}


int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* returnNums = (int*)malloc(sizeof(int)*1000); // 定义返回数组
    *returnSize = 0; // 返回数组长度置0
    if(root == NULL) // 如果根结点为空，直接返回
    {
        return returnNums;
    }
    pstack ps = init_stack(); // 创建栈
    struct TreeNode* p = root; // p指向根结点
    while(p!=NULL || !is_empty(ps)) // 当p不为空，或者栈不为空执行循环
    {
        if(p!=NULL)
        {
            push(ps,p);
            p = p->left;
        }
        else
        {
            p = pop(ps);
            returnNums[*returnSize] = p ->val;
            *returnSize = *returnSize + 1;
            p = p->right;
        }
    }
    free(ps->pbase);// 释放结点
    free(ps); // 释放栈顶栈底指针
    return returnNums;
}


```