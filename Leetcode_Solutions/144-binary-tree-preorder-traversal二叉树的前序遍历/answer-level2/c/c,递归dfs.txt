### 解题思路
此处撰写解题思路

这里的一个问题是：题目给的输入是数组，当数组为NULL或者元素个数为0时，入参root就为NULL，但是我们不能返回NULL，依旧要返回数组，只不过 *returnSize 为0

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

int *g_res;
int g_index;

void dfs(struct TreeNode *root)
{
    if (root == NULL) {
        return;
    }
    g_res[g_index++] = root->val;
    dfs(root->left);
    dfs(root->right);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    g_res = calloc(100, sizeof(int));
    g_index = 0;
    dfs(root);
    *returnSize = g_index;
    
    return g_res;
}
```