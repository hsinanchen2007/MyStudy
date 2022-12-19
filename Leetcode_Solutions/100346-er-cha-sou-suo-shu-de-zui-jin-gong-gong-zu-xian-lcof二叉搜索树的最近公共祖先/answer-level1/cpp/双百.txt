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
    bool get_path(TreeNode* root, TreeNode* p,vector<TreeNode*> &path)
    {
        if(root==NULL)return false;
        path.push_back(root);
        if(root==p)return true;
        if(get_path(root->left,p,path))return true;
        if(get_path(root->right,p,path))return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1,path2;
        get_path(root,p,path1);
        get_path(root,q,path2);
        int i=1;
        for(;i<path1.size()&&i<path2.size();i++)
        {
            if(path1[i]!=path2[i])
                return path1[i-1];
        }
        return path1[i-1];
    }
};
```