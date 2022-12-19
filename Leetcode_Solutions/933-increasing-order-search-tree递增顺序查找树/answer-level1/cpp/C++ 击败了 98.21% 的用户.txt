### 代码
```cpp
class Solution {
public:
    TreeNode* cur;
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = new TreeNode(0);
        cur = res;
        changeTheConnection(root);
        return res->right;
    }

    void changeTheConnection(TreeNode* root){
        if(!root)return;
        changeTheConnection(root->left);
        root->left = NULL;
        cur->right = root;
        cur = root;
        changeTheConnection(root->right);
    }
};
```