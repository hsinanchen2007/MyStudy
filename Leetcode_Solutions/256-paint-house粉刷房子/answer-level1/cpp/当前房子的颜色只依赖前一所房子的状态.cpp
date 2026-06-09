```c++
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) {
            return 0;
        }

        for (int i = 1; i < costs.size(); i++) {
            costs[i][0] += std::min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += std::min(costs[i - 1][0], costs[i - 1][2]);
            costs[i][2] += std::min(costs[i - 1][0], costs[i - 1][1]);
        }

        int m = costs.size() - 1;
        return std::min(std::min(costs[m][0], costs[m][1]), costs[m][2]);
    }
};
```