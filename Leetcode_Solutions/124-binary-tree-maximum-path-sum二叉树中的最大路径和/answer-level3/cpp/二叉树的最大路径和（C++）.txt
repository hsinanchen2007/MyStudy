### 解题思路
这道题目主要就是考方法（全局变量）和思路：
1：最大路径不一定是从跟节点出发，所以dfs方法不能完全解决问题。有两种请款
2：情况一：最大路径和是从根节点出发
3: 情况二：最大路径和不是以根节点为端点，需要考虑两边。（这里代码处理十分有技巧，可以不用if-else，直接max( ,0)更为简洁）
4：方法：将最大路径和存放于全局变量maxSum中，初始化的时候应该让maxSum尽可能的小，INT_MIN而不是0，因为节点可能是负数。

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
    int maxSum = INT_MIN;
    // 每次只能返回单边的最大路径
    int dfs(TreeNode* root) {
        if (!root) return 0;

        int leftMax = max(dfs(root->left), 0);
        int rightMax = max(dfs(root->right), 0);
        int newPath = root->val + leftMax + rightMax; // 这个路径将会包含两种情况，因为上面用了max，丢弃的一边就为0了
        maxSum = max(newPath, maxSum); // 跟全局变量比较
        return root->val + max(leftMax, rightMax); //返回一定只能返回单边
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
```