### 解题思路
递归的写法很巧妙，保留上一个节点的值，回溯回来。

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

bool isRight(struct TreeNode* root, long lowest, long highest);
bool isValidBST(struct TreeNode* root){
    return isRight(root, -2147483650, 2147483650);
}
bool isRight(struct TreeNode* root, long lowest, long highest) {
    if (root == NULL) {
        return true;
    }
    if (root->val <= lowest || root->val >= highest) {
        return false;
    }
    return isRight(root->left, lowest, root->val) && isRight(root->right, root->val, highest);
}

```