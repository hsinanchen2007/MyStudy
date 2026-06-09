### 解题思路
两种遍历方式：1、选择当前节点，那么左右孩子节点不能选择
            2、不选当前节点，左右俩孩子节点可以选
减枝:对于选择当前节点的值的情况进行记录即可～

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
    unordered_map<TreeNode*,int> mp;
    int dfs(TreeNode* root,int flag)
    {
        if(root==NULL) return 0;
        else
        {
            if(flag==1)
                return dfs(root->left,0)+dfs(root->right,0);
            else
            {
                if(mp.find(root)!=mp.end())
                    return max(mp[root],dfs(root->left,0)+dfs(root->right,0));
                int tp=root->val+dfs(root->left,1)+dfs(root->right,1);
                mp[root]=tp;
                return max(mp[root],dfs(root->left,0)+dfs(root->right,0));
            }
        }
    }
    int rob(TreeNode* root) {
        return dfs(root,0);
    }
};
```