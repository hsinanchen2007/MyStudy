![image.png](https://pic.leetcode-cn.com/a29668ebd29e00f0fae71fb596cf4cea9b2e5da744bbabe9e18daf010e24ec43-image.png)

本质和LC105. 从前序与中序遍历序列构造二叉树一样

递归版
```cpp
TreeNode* dfs(vector<int>& inorder, int i1, int j1, vector<int>& postorder,
              int i2, int j2, unordered_map<int, int>& M) {
  if (i1 >= j1 || i2 >= j2) return NULL;
  auto root = new TreeNode(postorder[j2 - 1]);
  int rlen = j1 - M[postorder[j2 - 1]] - 1;  // 从中序序列获取右子树的长度
  root->right =
      dfs(inorder, j1 - rlen, j1, postorder, j2 - 1 - rlen, j2 - 1, M);
  root->left = dfs(inorder, i1, j1 - rlen - 1, postorder, i2, j2 - 1 - rlen, M);
  return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
  unordered_map<int, int> M;
  for (int i = 0; i < inorder.size(); i++) M[inorder[i]] = i;
  return dfs(inorder, 0, inorder.size(), postorder, 0, postorder.size(), M);
}
```
非递归版：
```cpp
TreeNode* buildTree(vector<int>& in, vector<int>& post) {
  if (in.empty()) return NULL;
  stack<TreeNode*> S;
  TreeNode *root = new TreeNode(post.back()), *cur = root;
  S.push(root);
  for (int i = post.size() - 2, j = in.size() - 1; i >= 0; i--) {
    TreeNode *back = NULL, *cur = new TreeNode(post[i]);
    while (!S.empty() && S.top()->val == in[j]) back = S.top(), S.pop(), j--;
    if (back)
      back->left = cur;
    else
      S.top()->right = cur;
    S.push(cur);
  }
  return root;
}
```

