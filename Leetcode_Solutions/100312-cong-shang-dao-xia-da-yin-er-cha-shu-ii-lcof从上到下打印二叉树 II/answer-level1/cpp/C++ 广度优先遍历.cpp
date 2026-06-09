***Talk is cheap. Show me the code.***

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if (root == nullptr) return results;
        queue<TreeNode *> quk;
        quk.push(root);
        while (!quk.empty()) {
            int size = quk.size();
            results.push_back(vector<int>());
            for (int i = 0; i < size; i++) {
                TreeNode *p = quk.front();
                quk.pop();
                results.back().push_back(p->val);
                if (p->left != nullptr) quk.push(p->left);
                if (p->right != nullptr) quk.push(p->right);               
            }
        }
        return results;
    }
};
```