### 解题思路
这是一个仅供参考的非递归做法，仅提供不同的思路，时空复杂度均不是最优。

### 代码

```cpp
int pathSum(TreeNode* root, int sum) {
    if (root == nullptr) return 0;
    unordered_map<TreeNode*, vector<int>> hash;
    queue<TreeNode*> q;
    q.push(root);
    int cnt = 0;
    while (!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        hash[cur].push_back(cur->val);
        for (int i = 0; i < hash[cur].size(); i++)
            if (hash[cur][i] == sum) cnt++;
        if (cur->left != nullptr) {
            q.push(cur->left);
            for (int i = 0; i < hash[cur].size(); i++)
                hash[cur->left].push_back(hash[cur][i] + cur->left->val);
        }
        if (cur->right != nullptr) {
            q.push(cur->right);
            for (int i = 0; i < hash[cur].size(); i++)
                hash[cur->right].push_back(hash[cur][i] + cur->right->val);
        }
    }
    return cnt;
}
```