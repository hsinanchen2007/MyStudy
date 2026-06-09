### 解题思路
此处撰写解题思路

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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return {};
        }
        function<void(TreeNode*)> dfsEdge = [&](TreeNode* node) {
            if (!node) {
                return;
            }
            if (!node->left && !node->right) {
                res.push_back(node->val);
                return;
            }
            dfsEdge(node->left);
            dfsEdge(node->right);
        };
        function<void(TreeNode*)> dfsLeft = [&](TreeNode* node) {
            if (!node) {
                return;
            }
            res.push_back(node->val);
            if (node->left) {
                dfsLeft(node->left);
                dfsEdge(node->right);
            } else {
                dfsLeft(node->right);
            }
        };
        function<void(TreeNode*)> dfsRight = [&](TreeNode* node) {
            if (!node) {
                return;
            }
            if (node->right) {
                dfsEdge(node->left);
                dfsRight(node->right);
            } else {
                dfsRight(node->left);
            }
            res.push_back(node->val);
        };
        res.push_back(root->val);
        dfsLeft(root->left);
        dfsRight(root->right);
        return res;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```