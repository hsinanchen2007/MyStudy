

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==nullptr) return res;
        vector<int> temp;
        helper(root,sum,temp);
        return res;
    }
    void helper(TreeNode* root, int sum, vector<int> temp){
        temp.push_back(root->val);
        sum -= root->val;
        if(sum == 0 && root->left == nullptr && root->right == nullptr){
            res.push_back(temp);
            return;
        }
        if(root->left != nullptr) helper(root->left,sum,temp);
        if(root->right != nullptr) helper(root->right,sum,temp);

    }
};
```