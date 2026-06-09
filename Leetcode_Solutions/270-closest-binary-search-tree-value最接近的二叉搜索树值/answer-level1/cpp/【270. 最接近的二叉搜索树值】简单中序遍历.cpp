## 思路
### 代码
```c++
class Solution {
public:
    int closestValue(TreeNode* root, double target) {        
        stack<TreeNode*> st;              
        double m = abs(target - root->val);        
        int ans = root->val;
        while (root != nullptr || !st.empty()) {            
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }
            TreeNode *node = st.top();           
            if (abs(node->val - target) < m) {
                m = abs(node->val - target);
                ans = node->val;
            }
            st.pop();
            root = node->right;
        }
        return ans;        
    }
};
```
