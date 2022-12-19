用栈实现，从左到右或者从右到左添加结点值。
内存浪费有点大。
```
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
           vector<vector<int>> res;
    if (root == NULL)
        return res;
    stack<TreeNode *> st;
    st.push(root);
    bool dir = false;
    while (!st.empty())
    {
        vector<int> vectemp;
        int size = st.size(); 
        stack<TreeNode *> te;
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = st.top();
            st.pop();
            vectemp.push_back(temp->val);
           
            if (dir)
            {
                if (temp->right)
                    te.push(temp->right);
                if (temp->left)
                    te.push(temp->left);
            }
            if (!dir)
            {
                if (temp->left)
                    te.push(temp->left);
                if (temp->right)
                    te.push(temp->right);
            }
        }
        dir = !dir;
        st.swap(te);
        res.push_back(vectemp);
    }
    return res;
    }
};
```
