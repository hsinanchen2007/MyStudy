### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    /*
    * 从0站开始，一直到k站都正常，在开往k+1站时没油，那么起点应该设置成k+1站
    * 当从k+1到end全部可以正常通行，rest>=0就可以说明能够开完全程
    */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 走完所有加油站的剩余油量
        int rest = 0;   
        // 从出发加油站出发，经过每一个加油站的油箱蓄油量
        int cap = 0;
        // 出发加油站的编号
        int start = 0;
        for (int i=0; i<gas.size(); i++) {
            cap += (gas[i] - cost[i]);
            rest += (gas[i] - cost[i]);
            // 没有足够的油开往下一个加油站，start从下一个油站开始，cap清零
            if (cap < 0) {
                start = i+1;
                cap = 0;
            }
        }
        return rest < 0 ? -1: start;
    }
};



#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int rest = 0;   
    int cap = 0;
    int start = 0;
    for (int i=0; i<gas.size(); i++) {
        cap += (gas[i] - cost[i]);
        rest += (gas[i] - cost[i]);
        if (cap < 0) {
            start = i+1;
            cap = 0;
        }
    }
    return rest < 0 ? -1: start;
}

int main() {
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout << canCompleteCircuit(gas, cost) << endl;
}





```