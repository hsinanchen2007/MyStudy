## 思路一：递归
### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root) {
            helper(root, res);
        }
        return res;   
    }  
    
    void helper(TreeNode *root, vector<int> &res) {
        if (root) {
            res.push_back(root->val);
            helper(root->left, res);
            helper(root->right, res);
        }
    }
};
```

## 思路二：迭代
### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }   
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            res.push_back(node->val);
            if (node->right) {
                st.push(node->right);                
            }
            if (node->left) {
                st.push(node->left);
            }
        }
        return res;
    }  
};
```



