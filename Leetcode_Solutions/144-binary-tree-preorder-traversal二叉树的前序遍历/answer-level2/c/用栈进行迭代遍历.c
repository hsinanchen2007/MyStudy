### 解题思路
此处撰写解题思路
看注释即可
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
int* preorderTraversal(struct TreeNode* root, int* returnSize){
        /*空树直接结束即可*/
    if(root==NULL)
    {
        (*returnSize) = 0;
        return NULL;
    }
    int *result = (int *)malloc(sizeof(int) * 100);
    (*returnSize) = 0;
    /*用栈实现迭代过程，用数组模拟栈*/
    struct TreeNode *stack[100],*self;
    int top = 0;/*栈的计数从1开始*/
    stack[++top] = root;/*根先入栈*/
    /*只要栈不为空*/
    while(top!=0)
    {
        /*出栈*/
        self = stack[top--];
        result[(*returnSize)++] = self->val;
        /*栈是FILO表，所以右子树先进栈，若用队列，则左子树进队列*/
        if(self->right!=NULL)
        {
            stack[++top] = self->right;
        }
        if(self->left!=NULL)
        {
            stack[++top] = self->left;
        }
    }
    return result;
}
```