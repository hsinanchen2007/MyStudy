### 解题思路


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
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return res;
        dfs(root,sum);
        return res;
    }
    void dfs(TreeNode* root,int sum){
        tmp.push_back(root->val);
        if(!root->left && !root->right && sum == root->val)
            res.push_back(tmp);
        if(root->left) dfs(root->left,sum - root->val);
        if(root->right) dfs(root->right,sum - root->val);
        tmp.pop_back();
    }
};
```