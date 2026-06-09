```
#define MAX 1000
typedef struct Stack{
    struct TreeNode* stack[MAX];
    int fl;
}Stack;

void firstTr01(struct TreeNode* root, int *ar, int* returnSize);              // 为递归实现
void firstTr02(struct TreeNode* root, int *ar, int* returnSize);               // 非递归，采用栈实现
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int *ar = (int *)malloc(sizeof(int) * MAX);
    //firstTr01(root, ar, returnSize);
    firstTr02(root, ar, returnSize);
    return ar;

}

void firstTr02(struct TreeNode* root, int *ar, int* returnSize)             // 非递归实现
{
    struct TreeNode* T = root;
    Stack S;
    S.fl = -1;
    while(T || S.fl != -1)
    {
        while(T)
        {
            ar[(*returnSize)++] = T->val;
            S.stack[++(S.fl)] = T;
            T = T->left;
        }
        if(S.fl != -1)
        {
            T = S.stack[(S.fl)--];
            T = T->right;
        }
    }
    ar[*returnSize] = '\0';
}

/*
void firstTr01(struct TreeNode* root, int *ar, int* returnSize)         // 递归实现        
{
    if(root)
    {
        ar[(*returnSize)++] = root->val;
        firstTr(root->left, ar, returnSize);
        firstTr(root->right, ar, returnSize);
    }
    ar[*returnSize] = '\0';
}
*/

```
