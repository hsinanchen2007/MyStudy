## 代码

```cpp
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int last_value = 0;
        stack<TreeNode*> st;
        auto p = root;
        while (p) {
            st.push(p);
            p = p->right;
        }
        while (!st.empty()) {
            auto p = st.top();
            st.pop();
            p->val += last_value;
            last_value = p->val;
            if (p->left) {
                p = p->left;
                while (p) {
                    st.push(p);
                    p = p->right;
                }
            }
        }
        return root;
    }
};
```