```
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_cost = 0, total_gas= 0;
        for(int i=0; i<gas.size(); i++) {
            total_cost += cost[i];
            total_gas += gas[i];
        }
        if(total_cost > total_gas) return -1;
        int sum = 0, start = 0;
        for(int i=0; i<gas.size(); i++) {
            sum += (gas[i] - cost[i]);
            if(sum < 0) {
                sum = 0;
                start = i+1;
            }
        }
        return start;
    }
};
```
