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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int> > ans;
        int ind = 1;
        while(!q.empty())
        {
            int lens = q.size();
            vector<int> t;
            for(int i = 0; i < lens; ++i)
            {
                auto cur = q.front();
                q.pop();
                if(cur == NULL) continue;
                t.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            if(ind % 2 == 0) reverse(t.begin(), t.end());
            ++ind;
            ans.push_back(t);
        }
        return ans;
    }
};
```