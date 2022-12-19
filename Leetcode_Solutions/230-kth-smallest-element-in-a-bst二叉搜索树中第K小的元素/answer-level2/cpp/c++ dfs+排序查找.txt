

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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        dfs(root,vec);
        sort(vec.begin(),vec.end());
        return vec[k - 1];
    }
    void dfs(TreeNode* root,vector<int> &vec)
    {
        if(root == NULL)
        return ;
        vec.push_back(root->val);
        dfs(root->left,vec),
        dfs(root->right,vec);
       
    }
};
```