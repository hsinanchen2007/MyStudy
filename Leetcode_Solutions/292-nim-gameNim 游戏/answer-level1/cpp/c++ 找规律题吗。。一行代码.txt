### 解题思路
想不到，最后竟然只有一行代码。。。

### 代码

```cpp
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
        if(n < 4) return true;
        if(n == 4) return false;
        vector<pair<bool, bool>> dp(3, pair<bool,bool>{false, false});
        for(int i = 0; i < 3; i++){
            dp[i].first = true;
            dp[i].second = false;
        }
        pair<bool, bool> cur;
        for(int i = 4; i <= n; i++){
            if(dp[0].second || dp[1].second || dp[2].second){
                cur.first = true;
                cur.second = false;
            }else{
                cout << i << " false" << endl;  // 输出发现只要是4的倍数，就会false，其他都为true
                cur.first = false;
                cur.second = true;
            }
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = cur;
        }
        return cur.first;
    }
};
```