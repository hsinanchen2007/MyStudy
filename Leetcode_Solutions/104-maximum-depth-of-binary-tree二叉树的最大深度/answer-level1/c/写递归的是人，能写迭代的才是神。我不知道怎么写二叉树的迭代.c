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

int g_depth = 0;
int process(struct TreeNode *root, int depth)
{
    if (root == NULL) {
        if (depth > g_depth) {
            g_depth = depth;
            return 0;
        }
    }
    else {
        depth += 1;
        process(root->left, depth);
        process(root->right, depth);
    }
    return 0;
}
int maxDepth(struct TreeNode* root){
    int depth = 0;
    
    process(root, depth);
    depth = g_depth;
    g_depth = 0;

    return depth;
}
```