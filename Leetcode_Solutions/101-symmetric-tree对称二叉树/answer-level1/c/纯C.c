### 解题思路
纯C

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
static bool Symmetric(struct TreeNode* leftNode, struct TreeNode* rightNode)
{
    if (NULL == leftNode && NULL == rightNode)
    {
        return true;
    }

    if (NULL == leftNode || NULL == rightNode)
    {
        return false;
    }

    return (leftNode->val == rightNode->val) &&           \
            Symmetric(leftNode->right, rightNode->left) && \
            Symmetric(leftNode->left, rightNode->right);
}

bool isSymmetric(struct TreeNode* root){
    return Symmetric(root, root);
}

```