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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        TreeNode * mi = new TreeNode(root->val);
        //root = mirrorTree(root);
        copyTree(root, mi);
        root = mirrorTree(root);
        return isSymmetric_1(root, mi);
    }

    void copyTree(TreeNode* root, TreeNode *mi){
        if (root == NULL){
            return;
        }
        if(root->left){
            TreeNode* left = new TreeNode(root -> left->val);
            mi -> left = left;
        }else{
            mi->left = NULL;
        }
        if(root->right){
            TreeNode *right = new TreeNode(root -> right->val);
            mi->right = right;
        }else{
            mi->right= NULL;
        }
 
        copyTree(root->left, mi->left);
        copyTree(root->right,mi->right);
    }

    bool isSymmetric_1(TreeNode* root, TreeNode* mi){
        if (root == NULL){
            return (mi == NULL);
        }
        if(mi == NULL){
            return (root == NULL);
        }
 
        if (root->val == mi->val){
            return(isSymmetric_1(root->right, mi->right)&&
            isSymmetric_1(root->left, mi->left));
        }else{
            return false;
        }
        
    }

    TreeNode* mirrorTree(TreeNode* root) {
        dfs(root);
        return root;
    }

    void dfs(TreeNode* root){
        if (root == NULL){
            return;
        }
        TreeNode * temp = root;
        temp = root -> right;
        root -> right = root -> left;
        root -> left = temp;
        dfs(root->right);
        dfs(root->left);
    }
};
```