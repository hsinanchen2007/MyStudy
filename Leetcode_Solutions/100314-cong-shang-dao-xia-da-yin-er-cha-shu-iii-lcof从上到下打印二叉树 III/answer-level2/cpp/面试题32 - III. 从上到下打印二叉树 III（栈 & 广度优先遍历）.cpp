```cpp []
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        stack<TreeNode *> stk1;
        stk1.push(root);
        stack<TreeNode *> stk2;
        while (!stk1.empty() || !stk2.empty()) {
            if (!stk1.empty()) {
                res.push_back(vector<int>());
                while (!stk1.empty()) {
                    TreeNode *cur = stk1.top();
                    stk1.pop();
                    res.back().push_back(cur->val);
                    if (cur->left != nullptr) stk2.push(cur->left);
                    if (cur->right != nullptr) stk2.push(cur->right);
                }
            }
            if (!stk2.empty()) {
                res.push_back(vector<int>());
                while (!stk2.empty()) {
                    TreeNode *cur = stk2.top();
                    stk2.pop();
                    res.back().push_back(cur->val);
                    if (cur->right != nullptr) stk1.push(cur->right);
                    if (cur->left != nullptr) stk1.push(cur->left);
                }
            }
        }
        return res;
    }
};
```
![Xnip2020-03-13_23-25-30.jpg](https://pic.leetcode-cn.com/552fd34fd8848799184acac9d83513c67f4e65c41b20f99499c1f248259192ef-Xnip2020-03-13_23-25-30.jpg)