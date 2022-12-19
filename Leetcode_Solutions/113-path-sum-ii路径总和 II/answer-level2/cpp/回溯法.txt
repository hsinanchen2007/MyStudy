### 解题思路
此处撰写解题思路

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
    vector<vector<int>> res;
    void dfs(TreeNode* root, int sum, vector<int>& path) {
        if(!root) {
            return;
        }

        if(!root->left && !root->right) {
            if(sum == root->val) {
                res.push_back(path);
                return;
            }
        }
        if(root->left){
            path.push_back(root->left->val);
            dfs(root->left, sum - root->val, path);
            path.pop_back();
            
        }
        if(root->right) {
            path.push_back(root->right->val);
            dfs(root->right, sum - root->val, path);
            path.pop_back();

        }
        return;
    }


public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        res.clear();
        if(!root) {
            return res;
        }
        vector<int> path;
        path.push_back(root->val);
        dfs(root, sum, path);
        return res;       
    }
};
```