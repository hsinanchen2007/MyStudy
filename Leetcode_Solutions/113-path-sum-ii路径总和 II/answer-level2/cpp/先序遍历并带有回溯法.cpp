```
class Solution {
    void preorder(TreeNode *root, int sum, vector<int> &v, vector<vector<int> > &vs){
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL && root->val==sum)
            vs.push_back(v);
        if(root->left) preorder(root->left,sum-root->val,v,vs);
        if(root->right) preorder(root->right,sum-root->val,v,vs);
        v.pop_back();
    }
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > vs;
        vector<int> v;
        if(root==NULL) return vs;
        preorder(root,sum,v,vs);
        return vs;
    }
};
```
