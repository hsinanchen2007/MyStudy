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

private:
    vector<vector<int>> res;

    void findPath(const TreeNode* root, int sum, vector<int> & v) {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)  //题目要求，终点是叶节点
            if (sum == root->val) {
                v.push_back(root->val);
                res.push_back(v);
                v.pop_back();
                return;
            }

        v.push_back(root->val);
        findPath(root->left, sum - root->val, v);
        findPath(root->right, sum - root->val, v);
        v.pop_back();

        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return res;
        vector<int> v;
        findPath(root, sum, v);
        return res;

    }
};
```