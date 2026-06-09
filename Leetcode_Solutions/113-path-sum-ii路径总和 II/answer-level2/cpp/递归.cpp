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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return res;
        vector<int> temp;
        DFS(root,temp,sum);
        return res;

    }
    void DFS(TreeNode* root,vector<int> temp,int sum)
    {
        if(root==NULL)
            return ;
        temp.push_back(root->val);
        if(root->left==NULL&&root->right==NULL)
        {
            if(sum==root->val)
                res.push_back(temp);
                return;            
        }
        if(root->left!=NULL)
            DFS(root->left,temp,sum-root->val);
        if(root->right!=NULL)
            DFS(root->right,temp,sum-root->val);
    }
};
```