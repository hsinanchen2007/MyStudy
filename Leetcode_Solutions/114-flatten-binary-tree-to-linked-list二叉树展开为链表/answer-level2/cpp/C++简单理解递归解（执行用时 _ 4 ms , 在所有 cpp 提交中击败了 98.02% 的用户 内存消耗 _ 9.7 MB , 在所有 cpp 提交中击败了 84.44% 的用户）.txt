执行用时 : 4 ms , 在所有 cpp 提交中击败了 98.02% 的用户 内存消耗 : 9.7 MB , 在所有 cpp 提交中击败了 84.44% 的用户
```
class Solution {
private:
    TreeNode* p(TreeNode *root){
        if(!root)   return root;
        if(root->left && root->right){
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
            TreeNode *lastright = p(root->right);
            lastright->right = root->left;
            root->left = NULL;
            return p(lastright->right);
        }
        else if(root->left){
            root->right = root->left;
            root->left = NULL;
            return p(root->right);
        }
        else if(root->right){
            return p(root->right);
        }
        else
            return root;
    }
public:
    void flatten(TreeNode* root) {
        p(root);
    }
};
```
