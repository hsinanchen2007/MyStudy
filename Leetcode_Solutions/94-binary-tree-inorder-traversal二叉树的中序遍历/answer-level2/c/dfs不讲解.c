### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/9f470a9655146adcac6a8538d16019881b3055d2ed6b0dce599928e71171d67f-image.png)

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
    dfs(root->left);
    g_res[g_index++] = root->val;
    dfs(root->right);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    g_res = calloc(100, sizeof(int));
    g_index = 0;
    dfs(root);
    *returnSize = g_index;
    
    return g_res;
}
```