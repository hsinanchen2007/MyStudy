## 思路


### 代码

```cpp
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        stack<TreeNode*> st;      
        while (root || !st.empty()) {           
            while (root) {
                st.push(root);
                root = root->right;                
            }
            TreeNode *node = st.top();
            st.pop();
            if (--k == 0) return node->val;
            root = node->left;
        }
        return -1;
    }
};
```