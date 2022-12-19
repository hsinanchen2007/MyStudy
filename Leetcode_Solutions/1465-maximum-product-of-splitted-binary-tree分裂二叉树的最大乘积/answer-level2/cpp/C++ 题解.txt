### [1339. 分裂二叉树的最大乘积](https://leetcode-cn.com/problems/maximum-product-of-splitted-binary-tree/)

#### 题解

  + 递归求和，将$node->val$ 替换成所在子树的和
  + 递归求积，统计所有子树和整体断开时的积的最大值 = (整树和-子树和) * 子树和，需要用$long long int$存储
  + 结果取余 $10^9 + 7$
  + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)

#### 代码

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
    int maxProduct(TreeNode* root) {
        sum(root);
        return ans(root, root->val) % int(1e9+7);
    }
    int sum(TreeNode* root)
    {
        if(root == NULL) return 0;
        return root->val = sum(root->left) + sum(root->right) + root->val;
    }
    long long int ans(TreeNode* root, int sum){
        if(root == NULL) return 0;
        long long int res = (1LL * (sum - root->val) * root->val) ;
        return max(res, max(ans(root->left, sum), ans(root->right, sum)));
    }
};
```