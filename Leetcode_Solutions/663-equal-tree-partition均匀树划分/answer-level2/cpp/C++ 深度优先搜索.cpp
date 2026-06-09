```
class Solution {
public:
    int sum(TreeNode* root) {
        if (root == NULL) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    bool check(TreeNode* root, int total) {
        if (root == NULL) return false;
        if (2 * sum(root) == total) return true;
        return check(root->left, total) || check(root->right, total);
    }
    bool checkEqualTree(TreeNode* root) {
        if (root == NULL) return false;
        int total = sum(root);
        return check(root->left, total) || check(root->right, total);
    }
};
```
![image.png](https://pic.leetcode-cn.com/dec5cc31c3f99bb4bb0a67e9a4f764fbb1056d723e2ce2378fe960dd5803a00e-image.png)
