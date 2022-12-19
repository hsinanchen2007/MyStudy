
c99才可以用bool类型，否则自己定义

> #include <stdbool.h>

```c
bool isUnivalTree(struct TreeNode* root){
  bool left_correct = (root->left == NULL || (root->val == root->left->val && isUnivalTree(root->left)));

  bool right_correct = (root->right == NULL || (root->val == root->right->val && isUnivalTree(root->right)));

  return left_correct && right_correct;
}
```