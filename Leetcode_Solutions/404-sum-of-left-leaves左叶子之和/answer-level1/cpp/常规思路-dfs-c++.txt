### 解题思路
dfs即可
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
    int ans = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root) {
        if(root == NULL) return;
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
            ans += root->left->val;
            dfs(root->right);
            return;
        }
        dfs(root->left);
        dfs(root->right);
    }
};
```