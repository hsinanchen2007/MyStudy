```
class Solution {
public:
    int res;
    void helper(TreeNode* root,int &k){
        if(root==NULL||k==0) return;
        helper(root->right,k);
        k--;
        if(k==0){
            res=root->val;
            return;
        }
        helper(root->left,k);
    }
    int kthLargest(TreeNode* root, int k) {
        helper(root,k);
        return res;
    }
};
```
