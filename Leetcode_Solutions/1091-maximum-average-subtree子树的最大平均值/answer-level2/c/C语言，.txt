```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int g_sum;
int g_num;
double max_ans;
void dfs(struct TreeNode* root)
{
    int sum, sum1, num, num1;
    if (root != NULL) {
        g_num++;
        g_sum = g_sum + root->val;
    } else {
        return;
    }
    sum = g_sum;
    num = g_num;
    dfs(root->left);
    sum1 = g_sum - sum;
    num1 = g_num - num;
    if ((num1 > 0) && ((double)sum1) / num1 > max_ans) {
        max_ans = ((double)sum1) / num1;
    }
    sum = g_sum;
    num = g_num;
    dfs(root->right);
    sum1 = g_sum - sum;
    num1 = g_num - num;
    if ((num1 > 0) && ((double)sum1) / num1 > max_ans) {
        max_ans = ((double)sum1) / num1;
    }
}

double maximumAverageSubtree(struct TreeNode* root)
{
    g_sum = 0;
    g_num = 0;
    max_ans = -1;
    dfs(root);
    if ((g_num > 0) && ((double)g_sum) / g_num > max_ans) {
        max_ans = ((double)g_sum) / g_num;
    }
    return max_ans;
}
```
