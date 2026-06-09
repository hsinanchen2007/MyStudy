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
#define MAX 10240

typedef struct TreeNode Node;

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    if (!root)
        return 0;
    int *res = (int*)malloc(sizeof(int) * MAX);
    Node **stack = (Node**)malloc(sizeof(Node*) * MAX);
    int p = 1;
    int *visited = (int*)malloc(sizeof(int) * MAX);
    memset(visited, 0, sizeof(int) * MAX);
    stack[0] = root;
    Node *node;
    while (p)
    {
        do
        {
            if (visited[p - 1])
                break;
            visited[p - 1] = 1;
            node = stack[p - 1];
            if (node->right)
               stack[p++] = node->right;
            if (node->left)
               stack[p++] = node->left;
        } while (node->left || node->right);
        visited[p - 1] = 0;
        node = stack[--p];
        res[(*returnSize)++] = node->val;
    }
    return res;
}
```