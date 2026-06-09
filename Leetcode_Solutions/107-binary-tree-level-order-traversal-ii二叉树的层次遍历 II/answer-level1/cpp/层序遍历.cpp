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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(!root)
            return ans;
        q.push(root);
        while(!q.empty())
        {
            int k = q.size();
            vector<int> v;
            for(int i = 0 ; i < k ; ++i)
            {
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(v);
        }
        return vector<vector<int>>(ans.rbegin(), ans.rend());
    }
};
```