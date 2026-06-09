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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return{};

        vector<vector<int>> ans;
        int index=1;
        queue<TreeNode*> help;
        help.push(root);
        while(!help.empty())
        {
            vector<int> temp;
            int n=help.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* head=help.front();
                temp.push_back(head->val);
                if(head->left) help.push(head->left);
                if(head->right) help.push(head->right);
                help.pop();
            }
            if(index%2==0) reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            index++;
        }

        return ans;
    }
};
```