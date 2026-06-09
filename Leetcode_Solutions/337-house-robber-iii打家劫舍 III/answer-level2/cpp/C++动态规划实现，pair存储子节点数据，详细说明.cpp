
## 思路

**建议先使用动态规划的方法做 [打家劫舍 I](https://leetcode-cn.com/problems/house-robber/) 之后在做这道题，大体思路相同。**

和打家劫舍I一样，不能选择相邻的两个节点。所以对于一个子树来说，有两种情况：
1. 包含当前根节点
2. 不包含当前根节点

### 情况1：包含根节点

由于包含了根节点，所以不能选择左右儿子节点，这种情况的最大值为：**当前节点 + 左儿子情况2 + 右二子情况2**

### 情况2：不包含根节点

这种情况，可以选择左右儿子节点，所以有四种可能：
1. 左儿子情况1 + 右儿子情况1
2. 左儿子情况1 + 右儿子情况2
3. 左儿子情况2 + 右儿子情况1
4. 左儿子情况2 + 右儿子情况2

**综合来说就是，max(左儿子情况1, 左儿子情况2) + max(右儿子情况1, 右儿子情况2)。**

### 综合两种情况，深度优先，从叶子节点遍历到根节点即可。

## 代码实现

由于只有两种情况，可以选择使用pair来存储这两种情况的数据值。
pair的含义：<情况1包含当前节点的最大值，情况2不包含当前节点的最大值>

```c++
class Solution {
public:
    pair<int, int> dfs(TreeNode *root) {
        if (root == nullptr) {
            return { 0, 0 };
        }
        auto left_pair = dfs(root->left);
        auto right_pair = dfs(root->right);
        return { root->val + left_pair.second + right_pair.second, 
                max(left_pair.first, left_pair.second) + max(right_pair.first, right_pair.second) };
    }
    
    int rob(TreeNode* root) {
        auto p = dfs(root);
        return max(p.first, p.second);
    }
};
```