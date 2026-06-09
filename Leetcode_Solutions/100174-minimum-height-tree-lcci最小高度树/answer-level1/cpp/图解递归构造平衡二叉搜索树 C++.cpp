首先复习下二叉搜索树的定义：对于树中的所有子树都有，左子树上的值都小于根节点的值，右子树上的值都大于根节点上的值。总结一下就是，树的中序遍历可以得到一个升序序列。

如下图所示：
![二叉搜索树.png](https://pic.leetcode-cn.com/1eddc213e8d60914fc4c30223515b5b80a3baf9c97475986e165d081980a0ade-%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.png)

那如何保证高度最小呢？当树中的任意结点的左右子树高度差都不超过 1 时，整棵树的深度最小。

下面是一种构造最小高度树的思路：
1. 如果序列长度为 0，那么是一棵空树。
1. 如果序列长度为 1，那么只有一个根节点。
2. 如果长度大于 1，那么选取中间位置的数赋给根节点，然后前一半递归构建左子树，后一半递归构建右子树。

以 [-5,-3,0,1,5,9] 为例，构造过程如下图所示：

![构造平衡二叉搜索树.png](https://pic.leetcode-cn.com/cd4ef4ddf9fe87781a785e9eb737030e3045998ece798143021db42ce4f23401-%E6%9E%84%E9%80%A0%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.png)

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
    TreeNode* dfs(const vector<int> &nums, int L, int R) {
        if(L > R) {
            return nullptr;
        }
        int mid = (L+R)>>1;
        auto ptr = new TreeNode(nums[mid]); //填充根节点
        ptr->left = dfs(nums, L, mid-1); //构造左子树
        ptr->right = dfs(nums, mid+1, R); //构造右子树
        return ptr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
};
```
![qrcode_for_gh_6e5f8557b1f8_258.jpg](https://pic.leetcode-cn.com/fa6f677eb1fc90bb48f92537db002b605877bece35a1697162f0a10e3c3cbb7d-qrcode_for_gh_6e5f8557b1f8_258.jpg)

扫码关注，更多福利~