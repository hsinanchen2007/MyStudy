```
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
    vector<int> rightSideView(TreeNode* root) {
        if (root != nullptr) {
            add(root, 0);
        }
        return see;
    }

    void add(TreeNode* root, int idx) {
        if (root != nullptr) {
            if (see.size() > idx) {
                see[idx] = root->val;
            } else {
                see.push_back(root->val);
            }
        }
        if (root->left != nullptr) {
            add(root->left, idx + 1);
        }
        if (root->right != nullptr) {
            add(root->right, idx + 1);
        }
    }

private:
    vector<int> see;
};
```
