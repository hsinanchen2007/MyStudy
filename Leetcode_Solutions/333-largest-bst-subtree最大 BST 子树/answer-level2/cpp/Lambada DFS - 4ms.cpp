### 代码

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
    int largestBSTSubtree(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*, int&, int&)> dfs = [&dfs, &ans](TreeNode* node, int& maxi, int& mini)->int{
            int cnt = 0;
            if (node) {
                maxi = node->val;
                mini = node->val;
                int lmaxi = INT_MIN, lmini = INT_MAX;
                int leftCnt = dfs(node->left, lmaxi, lmini);
                if (leftCnt < 0 || (leftCnt > 0 && node->val <= lmaxi)) {
                    cnt = -1;
                } else if (leftCnt > 0) {
                    mini = lmini;
                }
                lmaxi = INT_MIN, lmini = INT_MAX;
                int rightCnt = dfs(node->right, lmaxi, lmini);
                if (rightCnt < 0 || (rightCnt > 0 && node->val >= lmini)) {
                    cnt = -1;
                } else if (rightCnt > 0) {
                    maxi = lmaxi;
                }
                if (cnt >= 0) {
                    cnt = leftCnt + rightCnt + 1;
                    ans = max(ans, cnt);
                }
            }
            return cnt;
        };
        int lmaxi = INT_MIN, lmini = INT_MAX;
        int cnt = dfs(root, lmaxi, lmini);
        return ans;
    }
};

auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```