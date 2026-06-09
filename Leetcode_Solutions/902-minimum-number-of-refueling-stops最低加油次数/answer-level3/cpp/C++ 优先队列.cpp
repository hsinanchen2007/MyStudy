```
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int reach = startFuel;
        int step = 0;
        int i = 0;
        priority_queue<int> fuels;
        while (true) {
            if (reach >= target) return step;
            ++step;
            for (; i < stations.size() && stations[i][0] <= reach; ++i) {
                fuels.push(stations[i][1]);
            }
            if (fuels.empty()) {
                break;
            } else {
                reach += fuels.top();
                fuels.pop();
            }
        }
        return -1;
    }
};
```

![image.png](https://pic.leetcode-cn.com/1d0a001c0418385fbeda186666e93e764a6907c4776511d96c675af49ca986fa-image.png)
