### 解题思路
此处撰写解题思路
前序遍历的首元素就是中序遍历的父节点，然后左右划分

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


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorder == NULL || preorderSize <= 0 || inorder == NULL || inorderSize <= 0) {
        return NULL;
    }
//printf("preOrdersize = %d, inorderSize = %d\n", preorderSize, inorderSize);

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    int i = 0;
    int temp = preorder[0];
    root->val = preorder[0];
    
    for (i = 0; i < preorderSize; i++) {
        if (inorder[i] == temp) {
            break;
        }
    }
//printf("i = %d\n", i);    

    root->left = buildTree(preorder + 1, i, inorder, i);
    root->right = buildTree(preorder + i + 1, preorderSize - i - 1, inorder + i + 1, inorderSize - i - 1);

    return root;
}
```