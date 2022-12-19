### 解题思路
终于终于通过了，之前一直想要用两个指针去做，结果改改改，总有不能通过的实例，突然想到，我这是动态规划模块的题呀，才想到是分成子问题去解。
状态方程：
    curMax=max(curMax, 当前值-当前最小值),
    初始状态：当前最小值minV=prices[0],curMax=0 

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len==0||len==1) return 0;
        int minV=prices[0];
        int curMax=0;
        for(int i=1; i<len; i++){
            if(prices[i]<minV)
                minV = prices[i];
            curMax = max((prices[i]-minV), curMax);
        }
        return curMax;
    }
};
```