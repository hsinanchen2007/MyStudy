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
class Solution 
{
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(!root) return true;

        vector<int> v1,v2;
        if(root->left) D_LR_RL(root->left,v1,1);
        if(root->right) D_LR_RL(root->right,v2,2);

        return v1==v2; 
    }

    int D_LR_RL(TreeNode* root,vector<int>& v,int mode)
    {
        stack<TreeNode*> s;

        while(root || !s.empty())
        {
            if(root)
            {
                v.push_back(root->val);
                s.push(root);
                if(mode==1) root=root->left;
                else root=root->right;
            }
            else
            {
                v.push_back(-1);
                if(mode==1) root=s.top()->right;
                else root=s.top()->left;
                s.pop();
            }
        }

        return v.size();
    }
};
```