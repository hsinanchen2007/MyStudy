### 解题思路
刚看到题目就觉得使用递归比较方便，实际写起来还有遇到些问题，判断如果left，right节点都为空，这就是叶子节点，返回1，否则就把left，right节点递归当做参数，递归调用，返回left，right中较大的值，再加上当前节点1。

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
  if (root == NULL)
    return 0;
  if (root->left == NULL && root->right == NULL)
    return 1;
    int leftcount = maxDepth(root->left);
    int rightcount = maxDepth(root->right);
  if (leftcount > rightcount) {
      return leftcount + 1;
  } else {
      return rightcount + 1;
  }
}
```