### 解题思路

对于当前算法思路我只想说为何此种方法能不重不漏枚举所有丑数。

1.首先基于丑数性质，后边的丑数一定是前边的丑数乘以一个质数得到，因此当前最小丑数一定是通过所有之前丑数乘以所有质数的组合出来的，也就是枚举到i个丑数时(i-1)*k个中一定有当前需要的那个。

2.用index数组记录当前已经遍历过的值，意味着从上述（i-1）*k个可能丑数中去掉了一部分已经放入队列的数，并且这样可以造成每次找最小的也就是最新的这种最优，因此算法可行。最后就只需要找 k个数中的最小即可。

### 代码

```cpp
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k=primes.size();
        vector<int> dp(n+1,INT_MAX);
        vector<int> index(k,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<k;j++){
                dp[i]=min(dp[i],primes[j]*dp[index[j]]);
            }
            for(int j=0;j<k;j++){
                if(dp[i]/dp[index[j]]==primes[j]){
                    index[j]++;
                }
            }
        }
        return dp[n-1];
    }
};
```