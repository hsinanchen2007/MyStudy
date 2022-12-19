### 解题思路
难点：
1. 为什么gas-cost>0就一定有解？（数学问题）
2. 为什么右边跑到终点可以就一定可以跑遍全程？（需要结合上一问的结论，且题目指出只有一个解，所以只要抓到一个可能的即可）
3. 为什么中间的点可以被认为不可能？（起点到终点有正积累都不可能，中间从零开始更不可能）

### 代码

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum_gain = 0;
        int run = 0;
        int startpos = 0;
        for (int i=0; i<gas.size(); i++) {
            sum_gain += gas[i]-cost[i];
            run += gas[i]-cost[i];
            if (run < 0) {
                startpos = i+1;
                run = 0;
            }
        }
        return sum_gain >= 0 ? startpos : -1;
    } 
};
```