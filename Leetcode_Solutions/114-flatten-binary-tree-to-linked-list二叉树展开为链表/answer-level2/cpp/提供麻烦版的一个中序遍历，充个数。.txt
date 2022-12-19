```
class Solution {
private:
     TreeNode* dfs(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        auto right = root->right;
        root->right = dfs(root->left);
        root->left = nullptr;
        TreeNode* tmp = root;
        while(tmp->right != nullptr){
            tmp = tmp->right;
        }
        tmp->right = dfs(right);

        return root;
    }

public:
    void flatten(TreeNode* root) {
        root = this->dfs(root);
    }
};
```
