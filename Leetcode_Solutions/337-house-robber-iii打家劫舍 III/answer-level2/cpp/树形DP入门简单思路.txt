这题显然是树形的动态规划，动态规划最重要的一步就是定义状态和对每一种状态进行决策和状态转移，如果能写出状态转移方程并且符合题目要求，那基本上大致思路对的。稍加思索可以发现这题对于每一个结点有取和不取两种状态：
1. dp[u][**0**]表示**不选**当前结点$u$的情况下以$u$为根的子树所能得到得最大价值;
2. dp[u][**1**]表示**选**当前结点$u$的情况下以$u$为根的子树所能得到得最大价值.

对于第一种情况，如果**不选**$u$，那么$u$的儿子${v_i}$无论选不选都无所谓，因为$u$已经将他们隔开，因此每个儿子按照贪心的策略应该把自己最大的价值传递给$u$，即
$dp[u][0] = \sum\limits_{v \in u.son}{max(dp[v][0], dp[v][1])}$
对于第二种情况，如果**选**$u$，那么$u$的儿子${v_i}$一定不能选，因为相邻的两个点不能同时被选中，因此每个儿子只能把自己不选的价值传递给$u$，即
$dp[u][1] = \sum\limits_{v \in u.son}{dp[v][0]}$

最后的答案就是$max\{dp[u_i][0], dp[u_i][1]\}, u \in tree$

```
class Solution {
public:
    int ans = 0;
    typedef pair<int,int>pii;
    /*
    dp[u][0] = sum{max(dp[v][1], dp[v][0])};
    dp[u][1] = sum({dp[v][0]+u.val})
    */
    pii dfs(TreeNode* u)
    {
        if(!u)
            return pii(0,0);
        pii ret(0,u->val);
        if(u->left){
            pii t = dfs(u->left);
            ret.first+=max(t.first, t.second);
            ret.second+=t.first;
        }
        if(u->right){
            pii t = dfs(u->right);
            ret.first+=max(t.first, t.second);
            ret.second+=t.first;
        }
        ans = max({ans, ret.first, ret.second});
        return ret;
    }
    int rob(TreeNode* root) {
        pii _ = dfs(root);
        return ans;
    }
};
```
