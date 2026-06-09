### 解题思路
一次遍历，对于每个加油站都进行current_tank计算，总gas必须大于等于cost才能环行一圈，如果当前结点站的存储油小于0则起点站后移一个

### 代码

```cpp
/*一次遍历，对于每个加油站都进行current_tank计算*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int n = gas.size();
            int total_tank = 0, curr_tank = 0;
            int starting_station = 0;
            for(int i=0;i<n;i++){
                total_tank += gas[i] - cost[i];
                curr_tank += gas[i] - cost[i];
                // 如果当前结点油量不够
                if(curr_tank < 0){
                    // 选择下一个结点站作为起始站
                    starting_station = i + 1;
                    curr_tank = 0;
                }
            }
            return  total_tank >= 0 ? starting_station : -1;
        }
};


/*双指针一次遍历，大神操作*/
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int G = accumulate(gas.begin(), gas.end(), 0);
//         int C = accumulate(cost.begin(), cost.end(), 0);
//         if (G < C) return -1;
//         int N = gas.size();
//         if (N == 1) return 0;
//         int l = 0;
//         int r = 1;
//         int s = gas[0] - cost[0];
//         while (l != r) {
//             if (s > 0) {
//                 s += gas[r] - cost[r];
//                 r = (r + 1) % N;
//             } else {
//                 l = (N + l - 1) % N;
//                 s += gas[l] - cost[l];
//             }
//         }
//         return l;
//     }
// };

```