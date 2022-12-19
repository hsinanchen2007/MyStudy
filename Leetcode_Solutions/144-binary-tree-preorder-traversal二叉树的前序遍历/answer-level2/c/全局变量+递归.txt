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
void preOrder(struct TreeNode* x){
    if(x){
        res[i++] = x->val;
        preOrder(x->left);
        preOrder(x->right);
    }
} 

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    i = 0;//全局变量，需要每次刷新
    struct TreeNode* x = root;
    preOrder(x);
    *returnSize = i;
    return res;
}
```