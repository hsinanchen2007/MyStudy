### 解题思路
此处撰写解题思路

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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>res;
        TreeNode* rt=root;
        while(rt||!st.empty())
        {
            while(rt)
            {
                st.push(rt);
                rt=rt->left;
            }
            rt=st.top();
            st.pop();
            res.push_back(rt->val);
            rt=rt->right;
        }
        return res;
    }
};
```