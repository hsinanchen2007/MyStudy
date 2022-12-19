### 解题思路
对每个节点来说，有可能是最大路径和的一部分，也有可能不是最大路径和的一部分。
如果是最大路径和的一部分那么分为如下几种情况：

1. 只有该节点
2. 该节点 + 左孩子路径
3. 该节点 + 右孩子路径
4. 该节点 + 左孩子路径 + 右孩子路径

根据该思路在DFS过程中不断更新答案，找出最优解。

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
private:
    const int INF = -0x3f3f3f3f;
    int ans = INF;
    int dfs(TreeNode* now) {
        if(now == nullptr) {
            return INF;
        }
        int ret = now->val;
        int r1 = dfs(now->left);
        int r2 = dfs(now->right);
        // left only, right only, left + right
        ans = max(max(max(r1, r2), r1 + r2 + ret), ans);
        // left + mid, right + mid, only mid
        ret = max(max(r1, r2) + ret, ret);
        ans = max(ret, ans);
        return ret;
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```