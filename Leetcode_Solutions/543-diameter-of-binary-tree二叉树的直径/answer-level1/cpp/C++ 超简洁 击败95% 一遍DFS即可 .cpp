### 解题思路
很容易想到求直径就是求左右两边最大的边的长度加起来，这个明显是一个递归可解决的问题
而返回值只能取一个，要么是最大长度 要么是最大直径 所以写起来最快的方式我们需要把其中一个值放到全局

我们在递归的时候只是返回当前节点的最大深度，即左右子节点的最大深度+1
然后每次都顺便更新一下最大直径，如果以当前节点为根节点的最大直径更大的话。

欢迎大家关注我的leetcode仓库～
[我的题解](https://www.github.com/wfnuser/leetcode)
[我的github](https://www.github.com/wfnuser)
[我的SICP习题解答](https://github.com/wfnuser/sicp-solutions/)
最近沉迷刷题 同时也在学习和实现lua，欢迎交流


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
    int ans = 1;

    int findMaxLength(TreeNode* root) {
        if (root == NULL) return 0;

        int left = findMaxLength(root->left);
        int right = findMaxLength(root->right);
        ans = max(ans, left + right + 1);

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        findMaxLength(root);

        return ans - 1;
    }
};
```