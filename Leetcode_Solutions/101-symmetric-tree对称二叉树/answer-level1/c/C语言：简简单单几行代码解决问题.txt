![QQ截图20190701140550.png](https://pic.leetcode-cn.com/543fcf16a9f878075841438257c8a8b970785207543ce7e606856a4c9d1f8526-QQ%E6%88%AA%E5%9B%BE20190701140550.png)

```
bool isSymmetric(struct TreeNode* root){
    if (root == NULL) return true;
    return fun(root->left, root->right);
}

int fun(struct TreeNode* l_root, struct TreeNode* r_root)
{
    if (l_root == NULL && r_root == NULL) return true;
    if (l_root == NULL || r_root == NULL) return false;

    return    (l_root->val == r_root->val)   &&
           fun(l_root->left,  r_root->right) &&
           fun(l_root->right, r_root->left);
}
```
