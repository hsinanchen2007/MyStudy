
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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> help;
        vector<int> temp={};

        help.push(root);
        while(!help.empty())
        {
            temp.clear();
            int len=help.size();
            for(int i=0;i<len;i++)
            {
                root=help.front();
                temp.push_back(root->val);
                help.pop();
                if(root->left) help.push(root->left);
                if(root->right) help.push(root->right);
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp.back());
        }
        
        return ans;
    }
};
```