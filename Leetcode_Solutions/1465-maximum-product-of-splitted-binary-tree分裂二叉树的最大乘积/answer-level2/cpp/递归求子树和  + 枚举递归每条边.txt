##思路
- 总体思路 ： 枚举去边 子树之和相乘 更新最大值
    - 子树的求和  ：  左子树 + 右子树 + 根   递归
    - 枚举去边    ：  根的左子树单独为一部分 剩下其他为一部分  同理 ： 根的右子树为单独一部分 剩下的为一部分
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
    #define LL long long
    LL ans;
    unordered_map<TreeNode*, int> sum;
    
    void get_sum(TreeNode* rt)
    {
        if(!rt) return;
        
        get_sum(rt->left);
        get_sum(rt->right);
        sum[rt] = sum[rt->left] + sum[rt->right] + rt->val;
    }
    
    void split(TreeNode* rt, int s)
    {
        if(!rt) return ;
        ans = max(ans, (LL)(s - sum[rt->left])*sum[rt->left]);     //拆左边 将根节点和其左子树分割
        ans = max(ans, (LL)(s - sum[rt->right])*sum[rt->right]);   //拆右边 将跟节点和其右子树分开
        split(rt->left, s); 
        split(rt->right,s);   // right 写错；
    }
    int maxProduct(TreeNode* root) {
        const int MOD = 1e9 + 7 ;
        get_sum(root);
        split(root, sum[root]);
        return ans % MOD;   //return  写成了 ruturn 
    }
};
```
