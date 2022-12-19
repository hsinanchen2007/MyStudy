### 解题思路
看代码吧，表达能力有限。

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
    vector<int> v;
    vector<vector<int>> res;

    void findnext(TreeNode* t, int sum) {
        v.push_back(t->val);
        if (t->left == NULL && t->right == NULL && t->val == sum) res.push_back(v);
        if (t->left) findnext(t->left, sum - t->val);
        if (t->right) findnext(t->right, sum - t->val);
        v.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root) findnext(root, sum);
        return res;
    }
};
```