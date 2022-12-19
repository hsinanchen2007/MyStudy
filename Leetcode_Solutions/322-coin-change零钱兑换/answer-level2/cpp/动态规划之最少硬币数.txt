### 解题思路
此处撰写解题思路
状态方程：f(coins, amount) = min(f(coins[i], amount-coins[i]))+1, f(0)=0;

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
            if(amount<0 || coins.size()==0) return -1;  //判断最普遍的无解情况
            int dp[amount+1];   //用于存放各个子问题的解
            int realMin=amount;
            dp[0]=0;    //初始状态是f(0)=0
            for(int i=1; i<=amount; i++){
                for(int j=0; j<coins.size(); j++){
                    if(i-coins[j]<0) continue;  //首先判断这个状态是否存在
                    int curMin=dp[i-coins[j]];  //如果这个状态存在，记录这个状态
                    realMin=((realMin==-1||curMin<realMin)&&curMin!=-1)?curMin:realMin;
                    //当前的最小状态：curMin!=1的情况下，进行判断->如果当前状态小于非-1的之前最小状态，当前最小状态为当前状态，否则不变
                }
                dp[i] = (realMin==-1 ||realMin==i)?-1:(realMin+1); //动态规划的最终思路
                realMin = i+1;
            }
            return dp[amount];
    }
};
```