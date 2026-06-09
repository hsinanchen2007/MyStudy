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
#define MAX 10240

int findBottomLeftValue(struct TreeNode* root)
{
    int res;
    struct TreeNode *queue[MAX];
    int front = 0, rear = 1, count = 1, i, temp;
    queue[0] = root;
    struct TreeNode *node;
    while (front < rear)
    {
        temp = 0;
        for (i = 0; i < count; i++)
        {
            node = queue[front++];
            if (i == 0)
                res = node->val;
            if (node->left)
            {
                temp++;
                queue[rear++] = node->left;
            }
            if (node->right)
            {
                temp++;
                queue[rear++] = node->right;
            }
        }
        count = temp;
    }
    return res;
}
```