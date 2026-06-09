## 思路一：非递归
### 代码
```c++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            TreeNode *p = st.top();
            res.push_back(p->val);
            st.pop();
            root = p->right;
        }
        return res;
    }
};
```

## 思路二：递归
### 代码
```c++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        helper(root, res);
        return res;
    }
    void helper(TreeNode *root, vector<int> &res) {
        if (root) {
            helper(root->left, res);
            res.push_back(root->val);
            helper(root->right, res);
        }        
    }
};
```

