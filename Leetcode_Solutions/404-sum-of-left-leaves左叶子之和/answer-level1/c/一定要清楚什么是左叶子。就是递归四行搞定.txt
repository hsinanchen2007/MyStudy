![image.png](https://pic.leetcode-cn.com/90eb3aa0b26ce9c1a235eddfe7cafb578da3e01e131d83a062c06412ac3422d6-image.png)

错了好几次老是漏掉一些

```c
int sumOfLeftLeaves(struct TreeNode* root){
    if(root == NULL) return 0;
    if(root->left == NULL) return sumOfLeftLeaves(root->right);
    if(root->left->left == NULL && root->left->right == NULL) return root->left->val + sumOfLeftLeaves(root->right);
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}
```
