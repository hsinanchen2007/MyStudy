### 解题思路
按题意，我们只需要先序遍历树，记录前一个访问的节点，然后修改其左右节点，左节点置空，右节点为当前访问的节点。

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
    void flatten(TreeNode* root) {
        if (root) {
            stack<TreeNode*> st;
            st.push(root);
            TreeNode* prev = nullptr;
            while (!st.empty()) {
                auto t = st.top();
                st.pop();
                if (t->right) st.push(t->right);
                if (t->left) st.push(t->left);
                if (prev) {
                    prev->left = nullptr;
                    prev->right = t;
                }
                prev = t;
            }
        }
    }
};
```