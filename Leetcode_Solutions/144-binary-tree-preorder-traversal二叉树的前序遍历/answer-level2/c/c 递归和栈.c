前序遍历递归：
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode* root, int* res, int* count) {
    if (root) {
        res[*count]=root->val;
        *count+=1;
        dfs(root->left, res, count);
        dfs(root->right, res, count);
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){

    int *res = (int*)malloc(sizeof(int)*2000);
    int cnt = 0;
    dfs(root, res, &cnt);
    
    *returnSize = cnt;
    return res;
}
```

前序遍历使用栈：
```
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

    int *res = (int*)malloc(sizeof(int)*2000);
    int cnt = 0;
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*2000);
    int stackcnt = 0;

    struct TreeNode* p = root;
    
    while(p||stackcnt) {
        if(p) {
            res[cnt++]=p->val;
            stack[stackcnt++]=p;
            p=p->left;
        } else {
            p = stack[--stackcnt];
            p = p->right;
        }
        
    }
    *returnSize = cnt;
    return res;
}
```
