在这个题中，核心思想是考虑   A[i-2] 【?】 A[i-1] 【?】 A[i]，中间的大小比较状态是否发生变化
     一般来说，两个比较状态不同，那么dp[i] = dp[i-1] + 1
                        相同，那么dp[i] = 2
     但有特殊情况如下：
        当A[i] != A[i-1] 的时候，要重新从2计数（最大长度从A[i-1]算起）
        当A[i] == A[i-1] 的时候，要重新从1计数（A[i-1]就不能计入最大长度） 
```
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if(A.size() < 2) return A.size();
        if(A.size() == 2) return (A[0] != A[1]) + 1;
        int len = A.size();
        int dp[len];
        int max;
        dp[0] = 1;
        dp[1] = (A[0] != A[1]) + 1;
        max = dp[1] > dp[0] ? dp[1] : dp[0];
        for(int i = 2; i < len; i++){
                dp[i] = (A[i] != A[i-1]) ? (((A[i] > A[i-1]) != (A[i-1] > A[i-2])) ? dp[i-1] + 1 : 2) : 1;
            max = dp[i] > max ? dp[i] : max;
        }
        return max;
    }
};
```
自己瞎总结的动态规划三要素（如果有不对的还请批评指正）：
     1、数组长度的特殊情况考虑;
     2、dp前几个位以及最大值的初始值;
     3、递推公式的考虑角度;
        a.从dp[i-1]出发，考虑加入A[i]之后对dp[i]的影响，来决定是将A[i]加入，还是将A[i]舍弃;//本题情况
        b.从A[i]出发，考虑加入dp[i-1]之后对dp[i]的影响，来决定是将dp[i]加入，还是将dp[i-1]舍弃。//参考leetcode53最大子列和