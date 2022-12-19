```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*first:放, second.first:不放且被监视second.second不放且没被监视*/
    const long long INF = 1e9;
    pair<long long, pair<long long, long long>> dfs(TreeNode* cur) {
        if (cur == NULL) return {INF, {0, INF}};
        auto son1 = dfs(cur->left);
        auto son2 = dfs(cur->right);
        long long ret11, ret21, ret22;
        ret21 = min(son1.first + son2.second.first, son1.first + son2.first);
        ret21 = min(ret21, son2.first + son1.second.first);
        ret22 = son1.second.first + son2.second.first;
        ret11 = min(ret21, ret22);
        ret11 = min(ret11, son1.first + son2.second.second);
        ret11 = min(ret11, son1.second.second + son2.second.second);
        ret11 = min(ret11, son2.first + son1.second.second);
        ret11 = min(ret11, son1.second.first + son2.second.second);
        ret11 = min(ret11, son1.second.second + son2.second.first);
        ret11++;
        return {ret11, {ret21, ret22}};
    }
    int minCameraCover(TreeNode* root) {
        auto ret = dfs(root);
        return min(ret.first, ret.second.first);
    }
};
```
