### 解题思路
    思路就是左右递归构建子树，原函数中的参数都给安排好了所以还挺好写的，直接看代码应该更好理解。
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

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    struct TreeNode* head = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int mid;
    if(preorderSize > 0)
        head->val = preorder[0];
    else
        return NULL;
    for(int i = 0; i < inorderSize; i++)
    {
        if(inorder[i] == preorder[0])
            mid = i;
    }
    head->left = buildTree(preorder+1 , mid ,inorder, mid);
    head->right = buildTree(preorder+mid+1,inorderSize-mid-1,inorder+mid+1, inorderSize-mid-1);
    return head;
}
```