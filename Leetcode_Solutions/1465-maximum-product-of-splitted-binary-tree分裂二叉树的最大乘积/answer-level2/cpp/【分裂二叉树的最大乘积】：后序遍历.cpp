
#### 解题思路

这种题往往题目很吓人，但仔细分析之后就会发现还是老生常谈的做法。

1. 要求两棵子树和的最大乘积，那就得先求出两棵子树各自的和。
2. 分别求两棵子树的和显然很难做到，但我们可以很方便的其中一个子树的和。
3. 用整棵树的总和 减去求出的子树和，就得到了另一棵子树和。
4. 枚举所有子树，对乘积取最大。

这样这道题就变成了，树的遍历 以及 对树的结点求和 两种过程的结合：

```cpp
typedef long long LL;
class Solution {
public:
    // 计算整棵树的总和
    LL calRootSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return root->val + calRootSum(root->left) + calRootSum(root->right);
    }
    // 后序遍历的同时，求出子树和
    LL subTreeSum(TreeNode* root, LL rootSum, LL& ret) {
        if (root == NULL) {
            return 0;
        }
        LL leftSum = subTreeSum(root->left, rootSum, ret);
        LL rightSum = subTreeSum(root->right, rootSum, ret);
        LL subSum = root->val + leftSum + rightSum;
        // 对结果取最大
        ret = max(ret, (rootSum - subSum) * subSum);
        return subSum;
    }
    int maxProduct(TreeNode* root) {
        LL rootSum = calRootSum(root);
        LL ret = 0;
        subTreeSum(root, rootSum, ret);
        return ret % LL(1e9 + 7);
    }
};
```



#### 解释

这里使用后序遍历的同时求子树和，其实是一个累加的过程。利用前一次递归求好子树和(`leftSum`, `rightSum`)，加上当前结点值`root->val`，就得到了以当前结点为根节点的子树和。

这样做，比起以每个结点为根结点再单独进行子树求和，要减少大量的重复计算。

#### 最后

感谢您的观看！欢迎大家留言，一起讨论交流。

至此，您已经明白了使用后序遍历的解题思路，如果这篇文章对您有帮助，您可以扫描下方二维码关注我的公众号“小小算法”，感谢支持！

![小小算法.png](https://pic.leetcode-cn.com/1776597b2773892787b2a16738cd78feb346c5a5290273bce69275b0b66a0a95-%E5%AE%A3%E4%BC%A0%E5%9B%BE2.png)