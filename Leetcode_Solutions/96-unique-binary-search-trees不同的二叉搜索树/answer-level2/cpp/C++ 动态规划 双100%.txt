### 解题思路
对于问题n，设根元素在sorted后的下标为index，则能将排列方式按照index划分为n+1类
分别为(0，index，n-1),(1,index,n-2),...,(n-1,index,0)
含义为(左子树元素个数，index，右子树元素个数)。假设问题n的解为T(n)
那么其递推式就为T(n) = sum (T(i)*T(n-i-1)) for i from 0 to n-1
为了避免重复计算T(i)，我们使用数组dp储存先前已经算出的结果。

### 代码

```cpp
class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        dp[0] = dp[1] = 1;
        for(int i = 2;i <= n;i++){
            dp[i] = 0;
            for(int j = 0;j <= i-1;j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};
```