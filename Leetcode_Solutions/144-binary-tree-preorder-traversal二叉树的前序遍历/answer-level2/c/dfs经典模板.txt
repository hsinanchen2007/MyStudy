### 解题思路
dfs模板题， 按照前序遍历的方式 赋值

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
void dfs(struct TreeNode* root, int* ret, int* count)
{
    if (root == NULL) {
        return NULL;
    }
    ret[(*count)++] = root->val;
    dfs(root->left, ret, count);
    dfs(root->right, ret, count);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* ret = (int*)calloc(1000, sizeof(int));
    int count = 0;
    dfs(root, ret, &count);

    *returnSize = count;

    return ret;
}
```