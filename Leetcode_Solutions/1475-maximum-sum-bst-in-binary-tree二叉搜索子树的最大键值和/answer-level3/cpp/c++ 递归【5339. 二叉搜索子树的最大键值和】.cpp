### 解题思路
比赛时ac的解答是错误的，用例[9,4,10,null,null,6,11]错误，已发布的大多数题解都有这个问题。
多谢评论区978007503@qq.com指正。

当前节点为根的树是不是二叉搜索树和几个状态有关
1. 左子树是不是二叉搜索树
2. 右子树是不是二叉搜索树
3. 当前val是不是大于左子树最大val
4. 当前val是不是小于右子树最小val

我们确定root节点为根的树是不是二叉搜索树，需要其左右子树处理时返回四个值
1. 子树是不是二叉搜索树  vec[0]
2. 子树的最小值          vec[1]
3. 子树的最大值          vec[2]
4. 子树的sum值          vec[3]

根据左右子节点返回值，构造当前节点的返回
当左右子树的任一vec[0]为false，或者当前val <= 左子vec[2] 或者val >= 右子vec[1]时返回 {false,随意，随意，随意}
如果判断当前树是搜索树，则返回 {true, 左子v[1], 右子v[2], val + 左子v[3] + 右子v[3]}
另外注意的是null的处理，我这里返回了{true, INT_MAX, INT_MIN, 0}。

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
    int maxsum = 0;
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxsum;
    }
    vector<int> dfs(TreeNode* root) {
        if (!root) return {true, INT_MAX, INT_MIN, 0};
        auto lArr = dfs(root->left);
        auto rArr = dfs(root->right);
        int sum = 0, curmax, curmin;
        if (!lArr[0] || !rArr[0] || root->val >= rArr[1] || root->val <= lArr[2]) {
            return {false, 0, 0, 0};
        }
        curmin = root->left ? lArr[1] : root->val;
        curmax = root->right ? rArr[2] : root->val;
        sum += (root->val + lArr[3] + rArr[3]);
        maxsum = max(maxsum, sum);
        return {true, curmin, curmax, sum};
    }
};
```