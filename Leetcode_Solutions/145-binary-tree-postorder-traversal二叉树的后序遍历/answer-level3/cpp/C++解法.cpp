```C++
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* top = s.top();
            ans.push_back(top->val);
            s.pop();
            if (top->left) s.push(top->left);
            if (top->right) s.push(top->right);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```