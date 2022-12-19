记录父节点
```c []
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    struct TreeNode* temp = root;
    struct TreeNode* father = NULL;
    while (temp) {
        father = temp;
        temp = temp->val > val ? temp->left : temp->right;
    }
    temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->val   = val;
    temp->left  = NULL;
    temp->right = NULL;
    if (val > father->val)
        father->right = temp;
    else
        father->left = temp;
    return root;
}
```
