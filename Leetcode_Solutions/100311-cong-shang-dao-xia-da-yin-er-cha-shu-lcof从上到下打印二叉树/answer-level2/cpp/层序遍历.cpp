
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
    vector<int> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> help;
        help.push(root);
        while(!help.empty())
        {
            int len=help.size();
            for(int i=0;i<len;i++)
            {
                root=help.front();
                ans.push_back(root->val);
                help.pop();
                if(root->left) help.push(root->left);
                if(root->right) help.push(root->right);
            }
        }
        return ans;
    }
};
```