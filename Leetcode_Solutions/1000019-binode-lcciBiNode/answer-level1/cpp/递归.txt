```
class Solution {
    pair<TreeNode*, TreeNode*> convertBiNodeCore(TreeNode* root) {
        pair<TreeNode*, TreeNode*> res(NULL, NULL);
        if (root == NULL)
            return res;
        auto left = convertBiNodeCore(root->left);
        auto right = convertBiNodeCore(root->right);
        TreeNode* head = root;
        TreeNode* prev = root;
        if (left.first != NULL) {
            head = left.first;
            prev = left.second;
        }
        prev->right = root;
        root->right = right.first;
        root->left = NULL;
        return { head,right.second == NULL ? root : right.second };

    }

public:
    TreeNode* convertBiNode(TreeNode* root) {
        auto res = convertBiNodeCore(root);
        return res.first;
    }
};
```
