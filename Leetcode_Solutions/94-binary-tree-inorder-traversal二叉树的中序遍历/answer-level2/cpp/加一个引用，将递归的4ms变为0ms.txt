直接用递归：
```
class Solution {
public:
    vector<int> vec;    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(root)
        {
        inorderTraversal(root->left);
        vec.push_back(root->val);
        inorderTraversal(root->right);            
        }

        return vec;
    }
};
```

函数返回值变引用：
```
class Solution {
public:
    vector<int> vec;    
public:
    vector<int>& inorderTraversal(TreeNode* root) {
        
        if(root)
        {
        inorderTraversal(root->left);
        vec.push_back(root->val);
        inorderTraversal(root->right);            
        }

        return vec;
    }
};