### 解题思路
要注意底部状态的辨别。思考：如果要求不能有值相同的路径怎么办？

### 代码

```cpp
class Solution {
public:
    void pathSum_core(TreeNode* root, vector<vector<int>>& re, vector<int>& ans, int& sum_temp, int& sum) {
        if (root==NULL) return;
        if (root->left == NULL && root->right==NULL) {
            if (sum_temp+root->val==sum) {
                ans.push_back(root->val);
                re.push_back(ans);
                ans.pop_back();
            }
            return;
        }
        ans.push_back(root->val);
        sum_temp += root->val;
        pathSum_core(root->left, re, ans, sum_temp, sum);
        pathSum_core(root->right, re, ans, sum_temp, sum);
        sum_temp -= root->val;
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> re;
        vector<int> ans;
        int sum_temp = 0;
        pathSum_core(root, re, ans, sum_temp, sum);
        return re;
    }
};
```