递归翻转，空结点与叶结点不变，其余先翻转左右子结点，然后左右互换

代码：
```
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        else {
            if (root->left || root->right) {
                root->left = invertTree(root->left);
                root->right = invertTree(root->right);
                swap(root->left, root->right);
            }
            return root;
        }
    }
};
```
