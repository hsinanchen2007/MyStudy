### 解题思路
我到底哪里错了，为啥老报超时。看不出来啊。。。。。。。。。。。。。。。。。

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
struct TreeNode* convertBiNode(struct TreeNode* root){
    if(!root)
    {
        return root;
    }
    struct TreeNode *head = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode *pre=head;
    struct TreeNode *cur=root;
    head->left=NULL;
    head->right=NULL;
    head->val=0;
    struct _stack
    {
        struct TreeNode data[100];
        int top;
    }stack;
    while(stack.top!=0||cur)
    {
        while(cur)
        {
            stack.data[stack.top++]=*cur;
            cur=cur->left;
        }
        cur = &(stack.data[--stack.top]);
        pre->right=cur;
        cur->left=NULL;
        pre=cur;
        cur=cur->right;
    }
    pre = head->right;
    free(head);
    return pre;
}