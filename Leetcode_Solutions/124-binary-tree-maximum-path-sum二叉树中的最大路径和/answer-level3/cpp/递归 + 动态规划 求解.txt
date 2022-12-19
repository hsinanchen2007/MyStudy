第一次读题时，感觉这道题目甚是唬人。任意结点到任意结点的最大路径和，一下子让我联想到了图的最短路径问题，甚至我想先将树转化为一个图，再用 Floyd 算法求解。

但细细思考，其实并不用这么麻烦，考虑到树的结构，它的任意结点到任意结点的路径最多只有两种情况：

![在这里插入图片描述](https://pic.leetcode-cn.com/92f76d82c36a46a00ba270a01e47a077f6bfcba4f525aee1619e07da876b0ac1.png)
如上图，可能有两种情况：1. 拐个弯的；2. 一条直线下来。

搞清楚这两种可能的情况，一切就简单多了。

用递归/迭代均可以实现，为了简单，此处用递归。

边界情况：若结点为空，则返回 0.
分别计算左孩子、右孩子中的最大路径和（从底向上），若左孩子的最大路径和 + 右孩子的最大路径和 + 此处结点的权重最大，则对应情况 1 ；否则对应情况 2, 挑选左孩子的最大路径和、右孩子的最大路径和中较大的一个加到此处结点的权重上，此时若更新后的结点权重小于 0,说明这条路没必要走了（动态规划），需要将该结点的权重置 0, 继续向上走。

代码：
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
    int res = 0;
    int dfs( TreeNode* root){
        if( !root)  return 0;
        int left = dfs( root->left), right = dfs( root->right);
        if( left > 0 && right > 0)
            res = max( root->val + left + right, res);
        root->val += max( left, right);
        res = max( res, root->val);
        if( root->val > 0)
            return root->val;
        return 0;
    }
    int maxPathSum(TreeNode* root) {
        if( !root)  return 0;
        res = root->val;
        dfs( root);
        return res;
    }
};
```
