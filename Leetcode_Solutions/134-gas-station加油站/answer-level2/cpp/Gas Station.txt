### 解题思路
贪心法。
当前油箱中的汽油 curgas < 0 时，表明该出发点无法到达终点，修改出发点 idx = i+1。
若走完所有加油站， totalgas < 0, 则从任何加油站出发都不可能环路行驶一周。

### 代码

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curgas = 0, totalgas = 0, idx = 0, n = gas.size();
        for (int i = 0; i < n; ++i) {
            totalgas += gas[i] - cost[i];
            curgas += gas[i] - cost[i];
            if (curgas < 0) {
                curgas = 0;
                idx = i+1;
            }
        }
        return totalgas < 0 ? -1 : idx;
    }
};
```