### 解题思路
我们只关心每个工人能获得的最大profit，那可以想到对profit和difficulty排序，用来快速找到能完成最大利益任务。具体怎么排序呢?
可以把diffculty和profit对应的值放到一起，形成一个tuple，然后按照difficulty，然后profiit大小的关系
进行排序得到diffprofit。
同时对worker也排序，然后遍历worker，
对于当前的worker[i]，我们可以在diffprofit中一直往右找，直到对应的难度大于worker[i]，停止，这个过程中，记录遇到的最大的价值max_profit，那么对于下一个worker[i+1], 我们继续从上次的位置往右，找到一个j，diffprofit使得对应位置的难度刚好大于worker[i+1]
...
通过这样的方式，可以实现每个worker都能选择到最大的价值任务，时间复杂度是排序的nlogn

```python3 []
class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        diffprofit = sorted(map(tuple, zip(difficulty, profit)))
        worker.sort()
        ans = max_profit = i = 0
        for diff in worker:
            # move i to right as we can
            while i < len(diffprofit) and diffprofit[i][0] <= diff:
                max_profit = max(max_profit, diffprofit[i][1])
                i += 1
            ans += max_profit
        return ans
```
```c++ []
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        vector<vector<int>> diffprofit;

        for (int i = 0; i<profit.size(); i++){
            diffprofit.push_back({difficulty[i], profit[i]});
        }

        sort(diffprofit.begin(), diffprofit.end());
        sort(worker.begin(), worker.end());

        int i(0), max_profit(0), ans(0);
        for (int j = 0; j<worker.size(); j++){
            while (i < diffprofit.size() && diffprofit[i][0] <= worker[j]){
                max_profit = max(max_profit, diffprofit[i][1]);
                i++;
            }
            ans += max_profit;
        }
        return ans;
    }
};