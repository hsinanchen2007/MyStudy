### 代码
```cpp
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        backtrack(root, sum);
        return results;
    }
    
    void backtrack(TreeNode *node, int sum) {
        if (node == nullptr) return;
        result.push_back(node->val);
        sum -= node->val;
        if (node->left == nullptr && node->right == nullptr && sum == 0) {
            results.push_back(result);
            result.pop_back();
            return;
        }
        backtrack(node->left, sum);
        backtrack(node->right, sum);
        result.pop_back();
    }
    
private:
    vector<int> result;
    vector<vector<int>> results;
};
```