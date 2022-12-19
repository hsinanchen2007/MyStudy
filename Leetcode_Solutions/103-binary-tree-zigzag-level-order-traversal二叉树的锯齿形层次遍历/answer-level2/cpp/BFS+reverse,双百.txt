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
        if(root==NULL)
            return {};
        queue<TreeNode* >q;
        q.push(root);
        bool flag=false;
        vector<vector<int>>result;
        while(!q.empty())
        {
            int len=q.size();
            vector<int>res;
            for(int i=1;i<=len;i++)
            {
                TreeNode*temp=q.front(); 
                q.pop();
                res.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            if(flag)
            {
                reverse(res.begin(),res.end());
            }
            flag=!flag;
            result.push_back(res);
        }
        return result;
    }
};
```