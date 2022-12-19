### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> item;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        backTrack(root, sum);
        return res;
    }
    void backTrack(TreeNode* root, int sum){
        if(!root) return;
        sum -= root->val;
        item.push_back(root->val);
        if(!root->left && !root->right && sum == 0) res.push_back(item);
        backTrack(root->left, sum);
        backTrack(root->right, sum);
        item.pop_back();
    }
};
```