```cpp
void readS(vector<pair<int, int>>& V, string str) {
  int n = str.size(), i = 0, j = 0, val, dep;
  while (j < n) {
    i = j;
    while (j < n && str[j] == '-') j++;
    dep = j - i;
    i = j;
    while (j < n && str[j] != '-') j++;
    val = stoi(str.substr(i, j - i));
    V.push_back(make_pair(val, dep));
  }
}
TreeNode* recoverFromPreorder(string str) {
  if (str.empty()) return NULL;
  vector<pair<int, int>> V;  //节点值和深度
  readS(V, str);
  auto root = new TreeNode(V[0].first);
  stack<pair<TreeNode*, int>> S;
  S.push(make_pair(root, 0));
  for (int i = 1; i < V.size(); i++) {
    TreeNode* cur = new TreeNode(V[i].first);
    while (S.top().second >= V[i].second) S.pop();
    if (S.top().first->left)
      S.top().first->right = cur;
    else
      S.top().first->left = cur;
    S.push(make_pair(cur, V[i].second));
  }
  return root;
}
```
