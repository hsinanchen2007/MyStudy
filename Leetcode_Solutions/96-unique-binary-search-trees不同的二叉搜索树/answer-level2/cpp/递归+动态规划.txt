# 思路
题目只要计算出数量即可，没有要求具体的树，显然把1--n每个数字作为根节点计算可以生成的树的数量，然后再加起来就行。每个根节点都把1-n分成了两部分（二叉搜索的性质），这两部分分别构建二叉搜索树，数量相乘结果就是根节点能构建的数量。

# 递归
把0个和1个节点构建的树的数量视为1；
循环1-n，分别对第i个数作为根节点进行左右两部分进行递归求解，最后求和。
提交后发现超时，递归超时必有动态规划。
分析递归树，发现有重复子问题，因此采用了动态的常规套路 备忘录+转移方程+从底向上。 即可解决

```c++
// 递归超时，明显有重复的子问题，可用动态规划
// class Solution {
// public:
//     int numTrees(int n) {
//         if (n == 0 || n == 1)
//             return 1;

//         int ans = 0;

//         for (int i = 0; i < n; ++i)
//         {
//             ans += numTrees(i) * numTrees(n-i-1);
//         }
//         return ans;
//     }
// };

class Solution{
public:
    int numTrees(int n)
    {
        if (!n)
            return 0;
        int dp[100] = {0};
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];    
    }
};
```