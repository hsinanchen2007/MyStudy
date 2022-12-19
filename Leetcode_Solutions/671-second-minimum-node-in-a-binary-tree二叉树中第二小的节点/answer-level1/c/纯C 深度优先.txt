### 解题思路
纯C 深度优先 递归

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
int DFS(struct TreeNode* root, int min)
{
    if (NULL == root)
    {
        return -1;
    }

    if (root->val > min)
    {
        return root->val;
    }

    int left = DFS(root->left, min);
    int right = DFS(root->right, min);

    if (-1 == right)
    {
        return left;
    }

    if (-1 == left)
    {
        return right;
    }

    return left < right ? left : right;
}

int findSecondMinimumValue(struct TreeNode* root){
    return DFS(root, root->val);
}
```