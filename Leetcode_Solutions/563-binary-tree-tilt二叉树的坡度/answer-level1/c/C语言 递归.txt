### 解题思路
代码很简单 只不过效率有点低

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

int sum(struct TreeNode* root){ //求树所有节点和
    if(!root) return 0;
    return root->val + sum(root->left) + sum(root->right);
}

int findTilt(struct TreeNode* root){
    if(!root) return 0;
    return findTilt(root->left) + findTilt(root->right) + abs(sum(root->left) - sum(root->right));
}
```