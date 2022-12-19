### 解题思路
递归 深度优先

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
bool traverse(struct TreeNode* node, long min, long max)
{
    if (NULL == node)
    {
        return true;
    }
    
    long lValue = node->val;
    
    if (lValue < min || lValue > max)
    {
        return false;
    }

    return traverse(node->left, min, lValue-1) && traverse(node->right, lValue+1, max);
}

bool isValidBST(struct TreeNode* root){
    return traverse(root, LONG_MIN, LONG_MAX);
}
```