### 解题思路
层次遍历

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty()){
            TreeNode* cur_left = q.front();
            q.pop();
            TreeNode* cur_right = q.front();
            q.pop();
            if(cur_left == NULL && cur_right == NULL) continue;
            if(cur_left == NULL || cur_right == NULL) return false;
            if(cur_right->val != cur_left->val) return false;
            q.push(cur_left->left);
            q.push(cur_right->right);
            q.push(cur_left->right);
            q.push(cur_right->left);
        }
        return true;
}
};
```