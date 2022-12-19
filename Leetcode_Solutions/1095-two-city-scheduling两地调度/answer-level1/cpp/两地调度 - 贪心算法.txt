### 解题思路
- 对于这2N个人，按照去A地和去B地的费用之差从小到大排序
- 选出前N个去A地，后N个去B地

### 代码

```cpp
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](vector<int> a, vector<int>b){return a[0] - a[1] < b[0] - b[1];});
        int n = costs.size() / 2, cost = 0;
        for(int i = 0; i < n; i++){
            cost += (costs[i][0] + costs[i+n][1]);
        }
        return cost;
    }
};
```