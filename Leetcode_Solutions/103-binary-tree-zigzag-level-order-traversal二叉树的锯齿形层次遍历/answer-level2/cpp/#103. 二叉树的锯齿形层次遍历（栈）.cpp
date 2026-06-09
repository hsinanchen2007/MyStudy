***Talk is cheap. Show me the code.***
```
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        stack<TreeNode*> left, right;
        left.push(root);
        while (!left.empty() || !right.empty()) {
            if (!left.empty()) {
                result.push_back(vector<int>());
                while (!left.empty()) {
                    TreeNode* curr = left.top();
                    left.pop();
                    result.back().push_back(curr->val);
                    if (curr->left) right.push(curr->left);
                    if (curr->right) right.push(curr->right);
                }
            }
            if (!right.empty()) {
                result.push_back(vector<int>());
                while (!right.empty()) {
                    TreeNode* curr = right.top();
                    right.pop();
                    result.back().push_back(curr->val);
                    if (curr->right) left.push(curr->right);
                    if (curr->left) left.push(curr->left);
                }
            }
        }
        return result;
    }
}
```
![1108.png](https://pic.leetcode-cn.com/5a8c5e1f6b636db877b2e813d056a3a0422f4f7fac2ce7997dc4e689c93a4862-1108.png)

