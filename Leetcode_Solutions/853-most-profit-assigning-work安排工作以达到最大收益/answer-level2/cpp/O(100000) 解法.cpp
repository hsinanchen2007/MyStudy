整体思路：
1. 遍历difficulty数组， 用一个哈希表unordered_map<int,int> maxPro, 专门记录特定的某个难度下的最大的收益，因为在题解中出现了相同难度的工作可能有不同的收益的情况，因此用maxPro确定某个确定的难度下的最大收益。同时在遍历的过程中记录下最大难度maxDiff和最小难度minDiff。
2. 用一个0~maxDiff的数组maxProfit，数组索引i代表难度，maxProfit[i]代表难度不超过i的最大收益。
3. 遍历worker中每个元素e，找到e对应的最大收益。

这个算法只有n>=10^4时速度比排序算法快，其他时间效率并不好
```cpp
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
       unordered_map<int, int> maxPro;
       int maxDiff = 1,minDiff = 1;
        // 时间复杂度为O(n)
       for(int i = 0; i < profit.size(); ++i){
           maxPro[difficulty[i]] = max(maxPro[difficulty[i]], profit[i]);
           maxDiff = max(maxDiff, difficulty[i]);
           minDiff = min(minDiff, difficulty[i]);
       }
        // 时间复杂度O(1000000), 因为1<=difficulty[i] <=100000
       vector<int> maxProfit(maxDiff+1, 0);
       for(int d = minDiff; d<=maxDiff; ++d){
           if(maxPro.count(d))
                maxProfit[d] = max(maxProfit[d-1],maxPro[d]);
            else
                maxProfit[d] = maxProfit[d-1];
       }
       int ans = 0;
       // 时间复杂度O(n)
       for(auto&e:worker){
           if(e>maxDiff)
                ans += maxProfit[maxDiff];
            else
                ans += maxProfit[e];
       }
       return ans;
    }
};
```