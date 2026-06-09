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
static struct TreeNode* helper(int* postorder, int postorderSize, int* inorder, int inorderSize,
                               int postorder_index, int inorder_start, int inorder_end)
{
    if (postorder_index < 0 || inorder_start > inorder_end)
    {
        return NULL;
    }

    struct TreeNode* pNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    pNode->val = postorder[postorder_index];
    int index = inorder_end;

    while (inorder_start <= index)
    {
        if (postorder[postorder_index] == inorder[index])
        {
            break;
        }
        index--;
    }

    pNode->left = helper(postorder, postorderSize, inorder, inorderSize,
                         postorder_index - (inorder_end - index + 1), inorder_start, index - 1);
    pNode->right = helper(postorder, postorderSize, inorder, inorderSize,
                          postorder_index - 1, index + 1, inorder_end);

    return pNode;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    return helper(postorder, postorderSize, inorder, inorderSize, postorderSize - 1, 0, inorderSize - 1);
}
```