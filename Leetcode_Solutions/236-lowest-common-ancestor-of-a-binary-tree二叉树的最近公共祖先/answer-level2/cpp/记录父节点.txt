### 解题思路
比较奇特的是使用了两个不同的哈希表，一个用来记录每个节点的上一层parent，一个用来记录p的所有parent。最后只要从q开始往上找，第一个找到的就是正解。

### 代码

```cpp
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (NULL==root) return root;
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> que;
        que.push(root);
        bool _p = false;
        bool _q = false;
        while (!que.empty()) {
            int k = que.size();
            while (k != 0) {
                TreeNode* ptr = que.front();
                que.pop();
                if (ptr->left != NULL) {
                    que.push(ptr->left);
                    parent[ptr->left] = ptr;
                }
                if (ptr->right != NULL) {
                    que.push(ptr->right);
                    parent[ptr->right] = ptr;
                }
                if (ptr->left==p || ptr->right==p) _p=true;
                if (ptr->left==q || ptr->right==q) _q=true;
                if (_p && _q) break;
                k--;
            }
        }
        unordered_map<TreeNode*, bool> p_parent;
        p_parent[root] = true;
        TreeNode* node = p;
        while (node != root) {
            p_parent[node] = true;
            node = parent[node];
        }
        node = q;
        while (p_parent.find(node)==p_parent.end()) {
            node = parent[node];
        }
        return node;
    }
private:
};
```