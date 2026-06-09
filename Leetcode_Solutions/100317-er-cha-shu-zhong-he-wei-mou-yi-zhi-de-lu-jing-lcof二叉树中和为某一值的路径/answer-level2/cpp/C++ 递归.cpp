### 解题思路
递归实现。
用sum减去当前节点的val。然后递归左右子树是否能生成对应sum-val的path。如果可以的话，在返回的path里面加上root的val就行。

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
        if (root == NULL) return {};
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                return vector<vector<int>>(1, {root->val});
            } else {
                return {};
            }
        }
        vector<vector<int>> res;
        if (root->left != NULL) {
            auto vv = pathSum(root->left, sum-root->val);
            for (auto v : vv) {
                v.insert(v.begin(), root->val);
                res.emplace_back(v);
            }
        }
        if (root->right != NULL) {
            auto vv = pathSum(root->right, sum-root->val);
            for (auto v : vv) {
                v.insert(v.begin(), root->val);
                res.emplace_back(v);
            }
        }
        return res;
    }
};
```