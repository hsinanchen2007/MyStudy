从n叉树得到一个思路，可以和前序二叉树遍历一样，最后做个反转即可。

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (nullptr == root) { return {}; }
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* pNode = root;

        st.push(pNode);
        while (!st.empty()) {
            pNode = st.top();
            ans.push_back(pNode->val);
            st.pop();
            if (pNode->left) {
                st.push(pNode->left);
            }

            if (pNode->right) {
                st.push(pNode->right);
            }
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
```