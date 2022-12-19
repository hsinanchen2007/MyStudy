
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
    int minDiffInBST(TreeNode* root) {
        vector<int> use;
        help(use,root);
        int ans=INT_MAX;
        for(int i=0;i<use.size()-1;i++)
            ans=min(use[i+1]-use[i],ans);
        return ans;
    }

    void help(vector<int>& use,TreeNode* root)
    {
        if(root==NULL) return;
        help(use,root->left);
        use.push_back(root->val);
        help(use,root->right);
    }
};
```