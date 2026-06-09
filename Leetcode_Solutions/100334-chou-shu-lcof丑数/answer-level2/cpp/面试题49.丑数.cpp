### 解题思路
- 核心思路：动态规划，设置3个指针p2、p3、p5，第i个丑数dp[i]=min(dp[p2]\*2,dp[p3]\*3,dp[p4]\*4)
- 执行用时 :12 ms, 在所有 C++ 提交中击败了56.73%的用户
- 内存消耗 :7.7 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        int p2=0,p3=0,p5=0;
        vector<int>dp(n);
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=min(dp[p2]*2,min(dp[p3]*3,dp[p5]*5));
            if(dp[i]%2==0)p2++;
            if(dp[i]%3==0)p3++;
            if(dp[i]%5==0)p5++;
        }
        return dp[n-1];
    }
};
```