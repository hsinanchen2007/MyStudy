方法一 递归
```
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root,res);
        return res;
    }
    void helper(TreeNode* root,vector<int>& res){
        if(root==NULL) return;
        res.emplace_back(root->val);
        helper(root->left,res);
        helper(root->right,res);
    }
};
```
方法二 迭代
```
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> sk;
        vector<int> res;
        while(root||sk.size()){
            while(root){
                sk.push(root);
                res.emplace_back(root->val);
                root=root->left;
            }
            root=sk.top();sk.pop();
            root=root->right;
        }
        return res;
    }
};
```

