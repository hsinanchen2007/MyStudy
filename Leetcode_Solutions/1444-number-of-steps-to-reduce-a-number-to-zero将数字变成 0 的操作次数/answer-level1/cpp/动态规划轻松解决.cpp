### 解题思路
**1.明确数组含义**
dp[i]：表示当数字为i时，变成0的操作次数为dp[i]；
**2.寻找递推关系（状态转移方程）**
如果i是偶数，那么dp[i] = 1+dp[i/2]，加1是因为有个除以2的操作；
如果i是奇数，那么dp[i] = 1+dp[i-1]，加1是因为有个减1的操作；
**3.初始化**
显然，dp[0] = 0, dp[1] = 1;

### 代码

```cpp
class Solution {
public:
    int numberOfSteps (int num) {
        if(num<=3){
            return num;
        }
        vector<int>dp(num+1,0);
        dp[1] = 1;
        for(int i=2;i<=num;i++){
            if(i%2 == 0){
                dp[i] = 1+dp[i/2];
            }
            else{
                dp[i] = 1+dp[i-1];
            }
        }
        return dp[num];
    }
};
```