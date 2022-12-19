```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans,res;
        if(root==nullptr)
            return ans;
        ans=inorderTraversal(root->left);
        ans.push_back(root->val);
        res=inorderTraversal(root->right);
        ans.insert(ans.end(),res.begin(),res.end());
        return ans;
    }
};
```
