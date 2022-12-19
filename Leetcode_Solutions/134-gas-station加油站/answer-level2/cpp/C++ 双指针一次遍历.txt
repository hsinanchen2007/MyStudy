```C++ []
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int G = accumulate(gas.begin(), gas.end(), 0);
        int C = accumulate(cost.begin(), cost.end(), 0);
        if (G < C) return -1;
        int N = gas.size();
        if (N == 1) return 0;
        int l = 0;
        int r = 1;
        int s = gas[0] - cost[0];
        while (l != r) {
            if (s > 0) {
                s += gas[r] - cost[r];
                r = (r + 1) % N;
            } else {
                l = (N + l - 1) % N;
                s += gas[l] - cost[l];
            }
        }
        return l;
    }
};
```
![image.png](https://pic.leetcode-cn.com/52700a804004e41639397d1ba3e788d9c679e84204555b3b8287d7c5c3cfaf58-image.png)
