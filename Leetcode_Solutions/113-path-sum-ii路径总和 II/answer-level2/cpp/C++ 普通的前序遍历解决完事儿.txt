### 解题思路
这个和 **路径总和 I** 是毫无区别的，唯一添加的就是需要保存历史路径

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        dfs(root, sum, res, vector<int>());
        return res;
    }
private:
    // remain: 距离目标和还差多少
    // res: 需要返回的二维向量, 注意引用传递
    // v： 一维向量, 保存历史路径
    void dfs(TreeNode* root, int remain, vector<vector<int>>& res, vector<int> v){
        if(!root) return;
        v.push_back(root->val);
        if(!root->left && !root->right && root->val == remain){
            res.push_back(v);
            return;
        }
        dfs(root->left, remain - root->val, res, v);
        dfs(root->right, remain - root->val, res, v);
    }
};
```