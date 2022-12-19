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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        st.push(root);
        while(st.size())
        {
            auto node = st.top();st.pop();
            res.push_back(node->val);
            if (node->right) st.push(node->right);//不能把空节点放进去；
            if (node->left) st.push(node->left);
        }
        
        return res;
    }
};
```