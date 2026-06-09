

### 代码

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *curr;
        stack<TreeNode*> unprocessedList;
        unprocessedList.push(root);
        while (!unprocessedList.empty()) {
            curr = unprocessedList.top();
            unprocessedList.pop();
            while (curr) {
                res.push_back(curr->val);
                if (curr->right)
                    unprocessedList.push(curr->right);
                curr = curr->left;
            }
        }
        return res;
    }
};
```