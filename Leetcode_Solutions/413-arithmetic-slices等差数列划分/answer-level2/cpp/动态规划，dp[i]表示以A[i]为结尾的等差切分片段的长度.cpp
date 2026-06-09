### 分析与思考：

    将问题的规模减小，如果发现子问题的解和原问题存在某些关联，那就可以尝试一下动态规划思路，动态规划首先就是要找到合适的子问题，然后找出递推关系，很容易想到在某个等差数列后，再加一个数会发生什么情况？
    
    因此可以启发这道题的解法。

    拆分子问题，让dp[i]表示以A[i]为结尾的等差切分的个数，如果dp[i]非0，即以A[i]结尾存在等差切片

    那么dp[i]实际上就是以A[i]为结尾等差切片的最大长度-2

    如果A[i+1]可以和A[i]部分构成等差切片，那么显然，dp[i+1] = dp[i] + 1，因为把之前的等差数列长度增加了1，那么以A[i+1]为结尾的等差片段的左端可取的值多了一个

    如果dp[i]本身为0.说明不存在以A[i]为结尾的等差切片，那么此时考虑A[i+1] A[i] A[i-1]的等差关系，如果存在，则dp[i+1]=1，否则为0

    综上，其实只要i元素与前两个元素构成等差，那么dp[i]=dp[i]+1，否则为0 (因为这里的dp[i]表示的是个数而非长度)

```C++
class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A);
};

/*
int Solution::numberOfArithmeticSlices(vector<int> &A) {
    if (A.size() <3)
        return 0;
    vector<int> dp(A.size(), 0);
    int total = 0;
    for (int i = 2; i < A.size(); i++) {
        if ((A[i] + A[i -2]) == 2 * A[i - 1])
            dp[i] = dp[i-1] + 1;
        total += dp[i];
    }
    return total;
}
*/

// 实际上可以优化空间复杂度，因为dp数组可以不用，只要记录两个值即可
int Solution::numberOfArithmeticSlices(vector<int> &A) {
    if (A.size() < 3)
        return 0;
    int total = 0, dp0 = 0, dp1 = 0;
    for (int i = 2; i < A.size(); i++) {
        if ((A[i - 2] + A[i]) == 2 * A[i - 1])
            dp1 = dp0 + 1;
        else
            dp1 = 0;
        total += dp1;
        dp0 = dp1;
    }
    return total;
} 
```

**然后我发现，只用两个变量而不用dp数组，空间复杂度竟然增加？？？？神奇的Leetcode**