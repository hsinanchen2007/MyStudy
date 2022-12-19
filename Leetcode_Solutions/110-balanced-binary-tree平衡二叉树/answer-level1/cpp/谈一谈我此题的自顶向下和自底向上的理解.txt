此题实际同时存在自顶向下和自底向上的操作，
先看普通解法：

```cpp
int maxDepth(TreeNode* root) {
  if (!root) return 0;
  return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
bool isBalanced(TreeNode* root) {
  if (!root) return true;
  if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1) return false;
  return isBalanced(root->left) && isBalanced(root->right);
}
```
// 这里实际有两层递归，一层是maxDepth1，采用的是后续遍历,
// 二层是isBalanced1，采用的是前序遍历，是自顶向下的，这没啥毛病，但问题出在二层遍历每个节点时，都会进行一次一层遍历，而一层遍历有很多冗余操作，会带来效率问题！

考虑改进：
第二层的自顶向下的必须全部遍历完，这是无法避免的，但每次节点时的求maxDepth操作却可以减少，原因是maxDepth是自底向上的后序遍历，可以提前截断，当底层的子树不满足平衡树时，直接向上传递此树不是平衡树的信息（即返回子树深度为-1），而不是传递当前树的深度，这样可避免许多不必要的操作
```cpp
int maxDepth(TreeNode* root) {
  if (!root) return 0;
  int left = maxDepth(root->left), right = maxDepth(root->right);
  if (left == -1 || right == -1) return -1;
  int res = abs(left - right);
  return res > 1 ? -1 : (max(left, right) + 1);
}
bool isBalanced(TreeNode* root) { return maxDepth(root) != -1; }
```
