* 树这一类的问题，首先想到的就是递归和分治，如果需要避免重复计算子问题，则引入dp数组，但是递归一般是通用的思路
* 开始的时候，犯了很愚蠢的错误，想把元素遍历一遍，保存到数组中，然后和前两道一样的做法
* 后来想，不对，一维数组中，只有两个相邻关系，而树中，可能存在3个相邻关系，一维数组不可能保存树中所有元素的相邻关系，不管怎么遍历或者线索化，都会存在相邻关系的遗漏，因此这种思路毙掉

```C++
class Solution {
public:
    int rob(TreeNode* root);
    void postOrder(TreeNode *root, int &maxprofit, map<TreeNode *, int> &dp);
};

// 递归+dp思路
// dp[i]表示以i为根结点的树的能够获得的最大收益
// 则根据i节点是否选择，得到递推公式
// dp[i] = max(dp[i.left] + dp[i.right] , i.val + dp[i.left.left] + dp[i.left.right] + dp[i.right.left] + dp[i.right.right])
// 意思就是，当前节点可选择或者不选
// 如果不选，则左右儿子都可以选，并且都选
// 如果选择了根结点，则左右子树的根结点都不可以选择，应该选择左右子树的左右子树（但实际上左右儿子的左右儿子不一定存在）
// 根据以上的递推公式，考虑自底向上的遍历的同时，填充dp数组, dp数组的初始化显然是要根据那些叶子节点来，因为叶子节点没有左右儿子
// 因此，想到用后序遍历，在后续遍历的过程中，填充每个节点的dp值，算法利用递归来实现

void Solution::postOrder(TreeNode *root, int &maxprofit, map<TreeNode *, int> &dp) {
    // 递归基准情况，当前节点为叶子节点
    // 此情况下，以root为根的树的最大收益显然是选择自己
    if (root && !root->left && !root->right) {
        dp[root] = root->val;
        maxprofit = max(maxprofit, dp[root]);
        return;
    }
    // 按照后序遍历，递归左右子树，得到左右子树的最大收益
    if (root->left) postOrder(root->left, maxprofit, dp);
    if (root->right) postOrder(root->right, maxprofit, dp);
    // 填充根结点的dp
    // 计算选择根结点时候的最大收益
    int withoutRoot = dp[root->left]+dp[root->right];
    int withRoot = root->val;
    if (root->left) {
        if (root->left->left) withRoot += dp[root->left->left];
        if (root->left->right) withRoot += dp[root->left->right];
    }
    if (root->right) {
        if (root->right->left) withRoot += dp[root->right->left];
        if (root->right->right) withRoot += dp[root->right->right];
    }
    dp[root] = max(withoutRoot, withRoot);
    maxprofit = max(maxprofit, dp[root]);
}

int Solution::rob(TreeNode *root) {
    if (!root) return 0;
    int maxprofit = 0;
    map<TreeNode *, int> dp;
    postOrder(root, maxprofit, dp);
    return maxprofit;
}

```
