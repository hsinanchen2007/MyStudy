**方法一：自底向上交换**：官方题解形式：
```
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return NULL;
        TreeNode* tmp = root->right;
        root->right = invertTree(root->left);
        root->left  = invertTree(tmp);
        return root;
    }
};
```
该种方法是从最顶的根结点开始递归调用，但从最底层节点开始交换，直至根节点的左右节点。

**方法二：自顶向上交换**：《剑zhi  offer》形式：
```
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* tmpleft = root->left;
        root->left = root->right;
        root->right = tmpleft;
        invertTree(root->left);
        invertTree(root->right);
        return root;
        
    }
};
```
明显，该方法是从根节点开始逐层交换左右节点，直至叶子节点时返回。
