### 解题思路
此处撰写解题思路

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
 #define MAXSIZE 2000
struct TreeNode* stack[MAXSIZE];
 int top = -1;

 int res[MAXSIZE]; 
 int i = 0;

 void visitLeftTreeNode(struct TreeNode* x){
     while(x){
        res[i++] = x->val;
        if(x->right) stack[++top] = x->right;
        x = x->left;
     }
 }
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    i = 0;
    struct TreeNode* x = root;
    while(true){
        visitLeftTreeNode(x);
        if(top == -1) break;
        x = stack[top];
        top--;
    }
    *returnSize = i;
    return res;
}
```