根据BST特点查找，递归

代码：
```
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL)
            return NULL;
        else {
            if (root->val == val)
                return root;
            else if (root->val > val)
                return searchBST(root->left, val);
            else
                return searchBST(root->right, val);
        }
    }
};
```
