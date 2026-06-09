### 解题思路
对异常输入处理后，然后在原树结构基础上进行左右节点交换，然后分别对子树进行递归处理，双百
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


struct TreeNode* mirrorTree(struct TreeNode* root){
    if(root == NULL) {
        return NULL;
    }

    /* 进行左右交换 */
    struct TreeNode *tmp;
    tmp = root->right;
    root->right  = root->left;
    root->left   = tmp;

    /* 处理子树 */
    mirrorTree(root->left);
    mirrorTree(root->right);

    return root;
}
```