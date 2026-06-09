### 解题思路
dp[i]表示i位数可以构成的符合题意的个数，考虑i+1位数，可以在i位数的基础上进行构造，然而i位数包含了0—i-1位数字和i位数字，而0-i-1位数构造后得到的是i位数，所以重复了，因而要考虑去重，i+1位数应该全部由i位数构造，i位数的个数为dp[i]-dp[i-1],对于每个i位数，还能使用的数字为10-i，所以i+1位数为(dp[i]-dp[i-1])*(10-i),再加上i位数dp[i]即为i+1位数的总数；
      dp[i+1]=(dp[i]-dp[i-1])*(10-i)+dp[i];
     即dp[i]=(dp[i-1]-dp[i-2])*(10-(i-1))+dp[i-1];

### 代码

```cpp
class Solution {
public:
    int dp[11];
    int countNumbersWithUniqueDigits(int n) {
     dp[0]=1;
     dp[1]=10;
     dp[2]=91;
     for(int i=3;i<=n;i++)dp[i]=(dp[i-1]-dp[i-2])*(11-i)+dp[i-1];
     return dp[n];
    }
};
```