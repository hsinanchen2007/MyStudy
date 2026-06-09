解法源自：https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/discuss/143775/very-easy-to-understand-c%2B%2B-solution.
```
class Solution {
public:
    unordered_map<TreeNode* ,TreeNode*> parent; // parent[子] = 父
    unordered_set<TreeNode*> visited;           // 访问记录
    vector<int> res;                            // 结果
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        getParent(root);                        // 获得父
        dfs(target, K);                         // 遍历
        return res;
    }
    void getParent(TreeNode* root) {
        if (root == NULL) return;
        if (root->left != NULL) {parent[root->left] = root; getParent(root->left);}
        if (root->right != NULL) {parent[root->right] = root; getParent(root->right);}
    }
    void dfs(TreeNode* root, int k) {
        if (root == NULL || visited.count(root)) return;
        visited.insert(root);
        if (k == 0) {res.push_back(root->val); return;}
        dfs(root->left, k - 1);
        dfs(root->right, k - 1);
        if (parent.count(root)) dfs(parent[root], k - 1);
    }
};
```
