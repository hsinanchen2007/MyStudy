题解：开辟并维护一个dp[n]的数组，满足O(n)的额外空间。dp[]记录的是，对当前行的每一个元素，以该元素为路径的结束点所需要的路径长度。
在triangle中,对其中一个元素p，到达p点所需要的最短路径就是p点上面两个元素其中较小的路径值加上p点元素值。
dp[i]表示在这一行（代码中记为l行），到达第i个元素所需要的路径长度；（dp[]是对每一行都更新的）。
所以dp[i]的值为dp[i]和dp[i-1]中的较小值加上triangle中的该点元素值。
注意：  到达下一行之后，需要更新dp[]值，更新的顺序是从右往左，因为dp[i]的值取决于dp[i-1]，若从左往右更新，会影响dp[i+1]的计算。dp从右往左更新则不会这种问题。
对于左右边缘的边缘元素，其更新方法稍不同。

![gh.png](https://pic.leetcode-cn.com/ceee67a9703e19f450cc852f3faea794174904c142e822f7619c93252e7b021b-gh.png)
```
//动态规划,dp[]为在当前行以每一个元素结束的最小路径；
//额外空间O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int res=INT_MAX;
        int n=triangle.size();
        vector<int> dp(n);    //O(n)的空间
        if(n==0) return 0;
        dp[0]=triangle[0][0];
        if(n==1) return dp[0];
        for(int l=1;l<n;l++) {  //l表示当前三角形行的下标
            int i=l;
            while(i>=0) {
                if(i==l) dp[i]=dp[i-1]+triangle[l][i];
                else if(i==0) dp[i]=dp[0]+triangle[l][i];
                else dp[i]=min(dp[i],dp[i-1])+triangle[l][i];
                if(l==n-1) res=min(res,dp[i]);
                i--;
            }
        }
        return res;
    }
};
```
