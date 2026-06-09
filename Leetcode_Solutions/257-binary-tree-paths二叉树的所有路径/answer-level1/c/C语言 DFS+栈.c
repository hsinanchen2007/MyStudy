/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_ARRY    64
#define MAX_STACK   64
typedef struct {
    int node[MAX_STACK];
    int top;
}T_Stack;

void push(T_Stack * pStack, int val)
{
    if(pStack->top == MAX_STACK-1)
        return;

    pStack->node[pStack->top] = val;
    pStack->top++;
}

void pop(T_Stack * pStack)
{
    char res[8] = {0};
    if(pStack->top == 0)
        return ;

    pStack->top--;
}
/* 将栈中的值保存为路径 */
void stack2path(T_Stack * pStack, char * path)
{
    char tmp[8];
    int i;
    for(i = 0; i < pStack->top-1; i++) {
        sprintf(tmp, "%d->", pStack->node[i]);
        strcat(path, tmp);
    }
    /* 最后一个值不需要'->'箭头 */
    sprintf(tmp, "%d", pStack->node[i]);
    strcat(path, tmp);
}

void dfs_func(struct TreeNode* root, char ** res, T_Stack * pStack, int * n)
{
    if(root == NULL)    return ;
    
    push(pStack, root->val);                    //依次入栈记录路径
    if(root->left==NULL && root->right==NULL)   //走到叶子节点,路径结束
    {
        stack2path(pStack, &res[*n][0]);         //栈中的值就是路径
        (*n)++;
    }
    else
    {
        dfs_func(root->left, res, pStack, n);
        dfs_func(root->right, res, pStack, n);
    }
    pop(pStack);                             //出栈,保留共有路径
    
}

char ** malloc_2d()
{
    char ** res = (char**)malloc(sizeof(char *) * MAX_ARRY);
    for(int i = 0; i < MAX_ARRY; i++)
        res[i] = (char *)malloc(sizeof(char) * MAX_ARRY);

    for(int i = 0; i < MAX_ARRY; i++)
        for(int j = 0; j < MAX_ARRY; j++)
            res[i][j] = 0;

    return res;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    char ** res = malloc_2d();
    T_Stack stack = {0};
    *returnSize = 0;
    
    dfs_func(root, res, &stack, returnSize);

    return res;
}