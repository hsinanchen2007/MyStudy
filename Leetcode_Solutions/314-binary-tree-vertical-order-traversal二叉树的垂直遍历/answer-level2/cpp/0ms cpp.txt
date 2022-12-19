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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int,vector<int>> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto [tn,ind]=q.front();q.pop();
            if(tn==NULL)continue;
            mp[ind].push_back(tn->val);
            q.push({tn->left,ind-1});
            q.push({tn->right,ind+1});
        }
        vector<vector<int>> ret;
        for(auto &i:mp)ret.push_back(i.second);
        return ret;
    }
};
```