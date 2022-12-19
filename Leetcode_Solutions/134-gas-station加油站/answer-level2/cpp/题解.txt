### 解题思路
想清楚两点
1. 所有站里的油总量要>=车子的总耗油量.则必然有一个点满足开一圈的条件
2. 在满足条件一的前提下，明确前一个站点到这个站点剩余油量大于０，则这个站点不可能是起始站
### 代码

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int oil = 0;
        int total_oil = 0;
        for(int i = 0; i < gas.size();i++){
            oil = oil + gas[i] - cost[i];
            total_oil = total_oil + gas[i] - cost[i];
            if(oil < 0){
                start = i + 1;
                oil = 0;
            }
        }
        return total_oil >= 0 ? start:-1;
    }
};
```