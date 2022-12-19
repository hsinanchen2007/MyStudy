思路：利用二叉搜索树的性质，递归删除
      注意点：只用判断右边为空 一次就ok了
```
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;    
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->right) {                 //只用判断右边为空 一次就ok了，其他逻辑都可以在else中处理
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            else {
                TreeNode* successor = root->right; 
                while (successor->left)
                    successor = successor->left;
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }

};
```
