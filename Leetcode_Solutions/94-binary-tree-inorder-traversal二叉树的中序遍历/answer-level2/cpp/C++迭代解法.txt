```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        
        stack<TreeNode*> s;
        TreeNode* cur=root;
        while(cur!=nullptr || !s.empty()) {
            while(cur!=nullptr) {
                s.push(cur);
                cur=cur->left;
            }
            cur=s.top();
            s.pop();
            vec.push_back(cur->val);
            cur=cur->right;
        }
        return vec;
    }
};
```
