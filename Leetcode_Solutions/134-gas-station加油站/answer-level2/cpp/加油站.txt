### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int res = -1;
        for(int i = 0; i < n; ++i) {
            int flag = 0;
            int sum = 0;
            for(int j = i; j < n; ++j) {
                if (sum + gas[j] - cost[j] < 0) {
                    flag = 1;
                    break;
                } else {
                    sum = sum + gas[j] - cost[j];
                }
            }
            if (flag == 1) {
                continue;
            }
            int j = 0;
            for(; j < i; ++j) {
                if (sum + gas[j] - cost[j] < 0) {
                    break;
                } else {
                    sum = sum + gas[j] - cost[j];
                }
            }
            if (j == i) {
                res = j;
                flag = 2;
                break;
            }
        }
        return res;
    }
};
```