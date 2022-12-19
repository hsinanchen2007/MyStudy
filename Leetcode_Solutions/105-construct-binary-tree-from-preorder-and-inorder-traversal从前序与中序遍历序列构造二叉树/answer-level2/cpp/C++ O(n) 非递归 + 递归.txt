![image.png](https://pic.leetcode-cn.com/e51c49e522a5ce2daf7dd88f6fdd656bfc013f16720656690cc48a9a26d21954-image.png)

非递归
```cpp
TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
  if (pre.empty()) return NULL;
  stack<TreeNode*> S;
  TreeNode* root = new TreeNode(pre[0]);
  S.push(root);
  for (int i = 1, j = 0; i < pre.size(); i++) {  // i-前序序号，j-中序序号
    TreeNode *back = NULL, *cur = new TreeNode(pre[i]);
    while (!S.empty() && S.top()->val == in[j]) back = S.top(), S.pop(), j++;
    if (back)
      back->right = cur;
    else
      S.top()->left = cur;
    S.push(cur);
  }
  return root;
}
```

递归：
```cpp
TreeNode* dfs(vector<int>& P, int pi, int pj, vector<int>& Q, int qi, int qj,
              unordered_map<int, int>& M) {
  if (pi >= pj || qi >= qj) return NULL;
  int pos = M[P[pi]] - qi;  // 从中序序列获取左子树的长度
  auto root = new TreeNode(P[pi]);
  root->left = dfs(P, pi + 1, pi + pos + 1, Q, qi, qi + pos + 1, M);
  root->right = dfs(P, pi + pos + 1, pj, Q, qi + pos + 1, qj, M);
  return root;
}
TreeNode* buildTree(vector<int>& P, vector<int>& Q) {
  unordered_map<int, int> M;  //记录各数在中序中的位置
  for (int i = 0; i < Q.size(); ++i) M[Q[i]] = i;
  return dfs(P, 0, P.size(), Q, 0, Q.size(), M);
}
```
