### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        TreeNode* node = root;
        stack<TreeNode*> st;
        while (node->left) {
            st.push(node);
            node = node->left;
        }
        root = node;
        while (st.size()) {
            node->left = st.top()->right;
            node->right = st.top();
            node = node->right;
            st.pop();
        }
        node->left = nullptr;
        node->right = nullptr;
        return root;
    }
};
```