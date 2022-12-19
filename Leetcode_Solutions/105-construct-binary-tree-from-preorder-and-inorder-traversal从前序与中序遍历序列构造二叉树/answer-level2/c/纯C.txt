### 解题思路
纯C 递归 前序找根 中序分左右

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
static struct TreeNode* helper(int* preorder, int preorderSize, int* inorder, int inorderSize,
                               int preorder_index, int inorder_start, int inorder_end)
{
    if (preorder_index > preorderSize - 1 || inorder_start > inorder_end)
    {
        return NULL;
    }

    struct TreeNode* pNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    pNode->val = preorder[preorder_index];
    int index = inorder_start;

    while (index <= inorder_end)
    {
        if (preorder[preorder_index] == inorder[index])
        {
            break;
        }
        index++;
    }

    pNode->left = helper(preorder, preorderSize, inorder, inorderSize,
                         preorder_index + 1, inorder_start, index - 1);
    pNode->right = helper(preorder, preorderSize, inorder, inorderSize,
                          preorder_index + (index - inorder_start + 1), index + 1, inorder_end);

    return pNode;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    return helper(preorder, preorderSize, inorder, inorderSize, 0, 0, inorderSize - 1);
}
```