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
int SubTreeHeight(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    int leftHeight = SubTreeHeight(root->left) + 1;
    int rightHeight = SubTreeHeight(root->right) + 1;
    return (leftHeight > rightHeight) ? (leftHeight) : (rightHeight);
}

bool isBalanced(struct TreeNode* root){
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return true;
    if (abs(SubTreeHeight(root->left) - SubTreeHeight(root->right)) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
```