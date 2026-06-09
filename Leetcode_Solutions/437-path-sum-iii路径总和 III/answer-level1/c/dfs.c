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
int *g_res;
int g_sum;

void process(struct TreeNode *root, int index, int sum)
{
    if (root == NULL) {
        return;
    }

    g_res[index] = root->val;
    int s = 0;
    for (int i = index; i >= 0; i--) {
        s += g_res[i];
        if (s == sum) {
            g_sum++;
        }
    }

    process(root->left, index + 1, sum);
    process(root->right, index + 1, sum);
}

int pathSum(struct TreeNode* root, int sum){
    g_res = calloc(1000, sizeof(int));
    g_sum = 0;

    process(root, 0, sum);
    return g_sum;
}
```