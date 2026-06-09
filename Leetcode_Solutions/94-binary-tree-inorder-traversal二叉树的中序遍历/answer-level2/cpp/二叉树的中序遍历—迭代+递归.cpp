方法一 迭代
遍历时顺序：左子树->根节点->右子树，因此先将根节点压入栈中
```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> sk;
        vector<int> res;
        while(root || sk.size()){
            while(root){
                sk.push(root);
                root=root->left;
            }
            root=sk.top();sk.pop();
            res.emplace_back(root->val);
            root=root->right;
        }
        return res;      
    }
};
```
方法二 递归
```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root,res);
        return res;
    }
    void helper(TreeNode* root,vector<int>& res){
        if(root==NULL) return;
        helper(root->left,res);
        res.emplace_back(root->val);
        helper(root->right,res);
    }
};
```

