

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
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> help;
        int sum=0;

        help.push(root);
        sum+=root->val;
        ans.push_back(sum);
        while(!help.empty())
        {
            sum=0;
            int len=help.size();
            for(int i=0;i<len;i++)
            {
                root=help.front();
                sum+=root->val;
                help.pop();
                if(root->left) help.push(root->left);
                if(root->right) help.push(root->right);
            }
            ans.push_back(sum);
        }
        
        return ans.back();
    }
    
};
```