## 思路：中序遍历递归
### 代码
```c++
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root) {
            vector<int> vec;
            helper(root, vec);       
            for (int i = 1; i < vec.size(); ++i) {
                if (vec[i] <= vec[i - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
    void helper(TreeNode *root, vector<int> &vec) {
        if (root) {
            helper(root->left, vec);            
            vec.push_back(root->val);
            helper(root->right, vec);
        }
    }
};
```
### 另一种写法
```c++
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root) {     
            long pre = LONG_MIN;       
            return helper(root, pre);       
        }
        return true;
    }
    bool helper(TreeNode *root, long &pre) {
        if (root) {            
            if (!helper(root->left, pre)) {
                return false;
            }
            if (pre >= root->val) {                
                return false;
            }            
            pre = root->val;            
            if (!helper(root->right, pre)) {
                return false;
            }                       
        }
        return true; 
    }
};
```

## 思路二：中序遍历迭代
### 代码
```c++
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root) {
            stack<TreeNode*> st;
            TreeNode *pre = nullptr;                     
            while (root || !st.empty()) {
                while (root) {
                    st.push(root);
                    root = root->left;
                }
                TreeNode *p = st.top();
                st.pop();
                if (pre && pre->val >= p->val) {
                    return false;                    
                }
                pre = p;
                root = p->right;
            }
        }
        return true;
    }
};
```

