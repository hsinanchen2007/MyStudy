
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
    int findBottomLeftValue(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> help;
        help.push(root);
        while(!help.empty())
        {
            vector<int> temp;
            int len=help.size();
            for(int i=0;i<len;i++)
            {
                root=help.front();
                help.pop();
                temp.push_back(root->val);
                if(root->left) help.push(root->left);
                if(root->right) help.push(root->right);
            }
            ans.push_back(temp.front());
        }
        return ans.back();
    }
};
```