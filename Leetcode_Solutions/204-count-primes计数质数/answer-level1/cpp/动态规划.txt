### 解题思路
用动态规划方法

### 代码

```cpp
class Solution {
public:
    int countPrimes(int n) {

        vector<bool> dp(n,true);

        int cnt=0;

        for(int i=2;i<n;i++){
            if(dp[i]){
                cnt++;
                for(int j=1;i*j<n;j++){
                    dp[i*j]=false;
                }
            }
        }


        return cnt;
        

        
    }
};
```