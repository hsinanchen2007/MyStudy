### 解题思路

思路：回溯
1、题目明确需要求解最大路径和，并且可能不经过根节点，也就是相当于我们从根节点出发向单方向遍历的方法行不通了
2、选取某个节点为中心点，左右进行遍历，考虑左右子节点带来的增益进行统计
3、回溯过程其实就是一个剪枝的过程，针对中心节点，左右子树中较小增益的删除，而同时需要刷新最大值，因为针对当前节点左右节点同时累加的增益可能会刷新最大值。

该题同
[543. 二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/)
[687. 最长同值路径](https://leetcode-cn.com/problems/longest-univalue-path/)
其实也是同样的解法，二叉树的直径直接假定中心节点，更新左子树和右子树的最大长度
最长同值路径有点变更在于，左右子树和中心点val不一致的时候，需要把左右值修改为0

32ms 31.9M
--- wangtao HW-2020/3/11

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
    int maxsum = INT_MIN;

    int dfs(TreeNode* root)
    {
        if (root == NULL) return 0;

        int leftgain = max(dfs(root->left), 0);
        int rightgain = max(dfs(root->right), 0);

        maxsum = max(maxsum, root->val + leftgain + rightgain);

        return root->val + max(leftgain, rightgain);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxsum;
    }
};
```