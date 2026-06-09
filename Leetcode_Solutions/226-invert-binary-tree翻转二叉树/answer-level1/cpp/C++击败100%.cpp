![image.png](https://pic.leetcode-cn.com/0d88fedcf2a9d406bd593a692be23ad7b0d70361a062fa2fbde6306e8221afa0-image.png)


```
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)   return NULL;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
```
