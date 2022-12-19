### 解题思路
截取前面所有不满足条件的加油站（residue<0）,第一个满足条件的加油站。

### 代码

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
            return -1;
        // 如果总油量大于总路程，必有解
        // 剩余油量
        int residue = 0;    
        // 结果
        int res = 0;
        // 判断从res出发，是否能到达const.size() - 1(终点), 不用考虑环圈；
        for (int i = 0; i < gas.size(); i++) {
            residue += gas[i] - cost[i];
            // 如果从res出发不能到达i -1, 那么之前的耗油量必定大于总路程，所以将其剪切
            // 那后面的耗油量必定小于总路程，解必在后面，出发点直接为i + 1
            if (residue < 0) {
                // 重置剩余油量
                residue = 0;
                // 出发点
                res = i + 1;
            }
        }
        return res;
    }
};
```