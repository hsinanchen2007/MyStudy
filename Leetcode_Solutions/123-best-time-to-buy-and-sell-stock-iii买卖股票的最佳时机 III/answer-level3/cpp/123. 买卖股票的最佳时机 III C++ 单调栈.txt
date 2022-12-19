### 解题思路

一种比较简单的解法：单调栈
1.先计算每个节点i后面最大的买卖差值，利用单调栈逆序求解
2.计算当前节点i前面的最大买卖差值，两者相加，遍历取最大

但是这种方法，只适合k = 2的情况



```cpp
class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> rightvalues = vector<int>(prices.size(), 0);
        int rightmax = 0;
        int minvale = INT32_MAX;
        int leftmax = 0;
        int maxvalue = 0;
        deque<int> buff;

        for (int i = prices.size() - 1; i >= 0; i--) {
            while (!buff.empty() && prices[buff.front()] < prices[i]) {
                buff.pop_front();
            }

            buff.push_front(i);

            if (!buff.empty()) {
                rightmax = max(rightmax, prices[buff.back()] - prices[buff.front()]);
                rightvalues[i] = rightmax;
            }
        }

        rightvalues.push_back(0);

        for (int i = 0; i < prices.size(); i++) {
            minvale = min(minvale, prices[i]);
            leftmax = max(leftmax, prices[i] - minvale);
            maxvalue = max(maxvalue, leftmax + rightvalues[i + 1]);
        }

        return maxvalue;
    }
};
```





参考大神写的，唯一一点不同的是。对第二次买入和卖出作了索引限制。更好理解一点

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size()<2){
            return 0;
        }

        vector<vector<int>> dp = vector<vector<int>>(prices.size(),vector<int>(5,INT32_MIN));

        dp[0][0] = 0;
        dp[0][1] = 0 - prices[0];

        for(int i = 1;i<dp.size();i++){
            dp[i][0] =0;
            //1.dp[i][1] 表示第i轮第一次买入的最大值，其来源于两种策略：不操作和买入
            //不操作：dp[i][1] = dp[i-1][1]，说明之前已经操作过，当前保持即可
            //买入：dp[i][1] = dp[i][0]- prices[i] 
            //取两者的最大值；
            dp[i][1] = max(dp[i-1][1],dp[i][0]- prices[i]);

            //2.dp[i][2] 表示第i轮第一次卖出后的最大值，其来源于两种策略：不操作和卖出
            //不操作：dp[i][2] = dp[i-1][2]，说明之前已经卖出过，当前保持即可
            //卖出：dp[i][2] = dp[i-1][1]+ prices[i] ，用上一轮买入的钱+卖出的钱
            //取两者的最大值；            
            dp[i][2] = max(dp[i-1][2],dp[i-1][1]+ prices[i]);


            //3.dp[i][3] 表示第i轮第二次买出后的最大值，其来源于两种策略：不操作和买入              
            if(i>1){
                dp[i][3] = max(dp[i-1][3],dp[i-1][2]-prices[i]);
            }
            //4.dp[i][5] 表示第i轮第二次卖出后的最大值，其来源于两种策略：不操作和卖入  
            if(i>2){
                dp[i][4] = max(dp[i-1][4],dp[i-1][3]+prices[i]);
            }
                      
        }

        int length = dp.size()-1;

        return max(0,max(dp[length][2],dp[length][4]));
 

    }
};
```