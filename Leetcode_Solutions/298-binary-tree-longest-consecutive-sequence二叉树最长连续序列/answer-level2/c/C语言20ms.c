```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static int dfs(struct TreeNode *root, long long last, int step);
int longestConsecutive(struct TreeNode *root)
{
    return dfs(root, 10000000000, 0);
}

static int dfs(struct TreeNode *root, long long last, int step)
{
    if (root == NULL)
        return step;
    
    int curr_step = (last + 1 == root->val) ? step + 1 : 1;
    int left_step = dfs(root->left, root->val, curr_step);
    int right_step = dfs(root->right, root->val, curr_step);

    int max = (left_step > curr_step) ? left_step : curr_step;
    max = (right_step > max) ? right_step : max;
    return max;
}
```
