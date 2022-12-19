### 解题思路
虽然性能糟糕的很，不过为了可读性还是不做优化了……
里面有一些奇技淫巧的代码……见笑了。
### 代码

```cpp
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        multimap<int, int> expectProfit;
        multimap<int, vector<int>> end_start_profit;
        for (int i = 0; i<endTime.size(); i++)
            end_start_profit.insert({ endTime[i],{ startTime[i],profit[i] } });
        for (auto i = end_start_profit.begin(); i != end_start_profit.end(); i++)
        {
            int maxProfit = 0;
            int thisProfit = i->second[1];
            if (i == end_start_profit.begin()) maxProfit = thisProfit;
            else {
                int thisStart = i->second[0];
                int lastSumProfit = expectProfit.rbegin()->second;
                if ((--i)->first <= (i++,thisStart) ) maxProfit = lastSumProfit + thisProfit;
                else {
                    auto j = expectProfit.rbegin();
                    for (;j != expectProfit.rend() && j->first>thisStart; j++);
                    if (j == expectProfit.rend()) maxProfit = max(thisProfit, lastSumProfit);
                    else {
                        int remainSumProfit = j->second;
                        maxProfit = max(thisProfit + remainSumProfit, lastSumProfit);
                    }
                }
            }
            expectProfit.insert({ i->first,maxProfit });
        }
        return expectProfit.rbegin()->second;
    }
};
```