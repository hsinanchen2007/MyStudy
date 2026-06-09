
```cpp
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
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        function<void(TreeNode*, int, int&, int&)> dfs = [&](TreeNode* node, int v, int& ucnt, int& dcnt){
            if (!node) {
                return;
            }
            int lucnt = 0;
            int ldcnt = 0;
            int rucnt = 0;
            int rdcnt = 0;
            dfs(node->left, node->val, lucnt, ldcnt);
            dfs(node->right, node->val, rucnt, rdcnt);
            if (node->val == v + 1) {
                ucnt += max(lucnt, rucnt) + 1;
            } else if (node->val == v - 1) {
                dcnt += max(ldcnt, rdcnt) + 1;
            }
            ans = max({ans, ucnt, dcnt, lucnt + rdcnt + 1, rucnt + ldcnt + 1});
        };
        int ucnt = 0;
        int dcnt = 0;
        dfs(root, 1e8, ucnt, dcnt);
        return ans;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin.tie(0);
    return 0;
}();
```