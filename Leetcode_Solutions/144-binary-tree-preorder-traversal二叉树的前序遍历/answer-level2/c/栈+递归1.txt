### 解题思路
法1：递归，本题和下面两个遍历一起关联起来
和leetCode 94 中序 [https://leetcode-cn.com/problems/binary-tree-inorder-traversal/]()
leetCode 145 后序 [https://leetcode-cn.com/problems/binary-tree-postorder-traversal/]()

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
#define MAXSIZE 1000

void recursion(struct TreeNode* root, int* res, int* count) {
    if (root) {
        res[*count] = root->val;
        (*count) ++;
        recursion(root->left, res, count);
        recursion(root->right, res, count);
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){

    int *arr = (int*)malloc(sizeof(int)*MAXSIZE);
    int cnt = 0;
    recursion(root, arr, &cnt);
    
    *returnSize = cnt;
    return arr;
}

```
法2：用数组栈，入栈需要先右后左，这样输出才可以先左后右。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAXSIZE 1000

//void recursion(struct TreeNode* root, int* res, int* count) {
//    if (root) {
//        res[*count] = root->val;
//        (*count) ++;
//        recursion(root->left, res, count);
//        recursion(root->right, res, count);
//    }
//}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){

    int *arr = (int*)malloc(sizeof(int)*MAXSIZE);
    int cnt = 0;
    //recursion(root, arr, &cnt);

    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAXSIZE);
    int top = -1;
    if(!root)
    {
        *returnSize = cnt;
        return NULL;
    }
    stack[++top] = root;

    while(top != -1)
    {
        root = stack[top --];
        arr[cnt++] = root->val;
        if (root->right)
        {
            stack[++top] = root->right;
        }
        if (root->left)
        {
            stack[++top] = root->left;
        }
        
    }
    
    *returnSize = cnt;
    return arr;
}