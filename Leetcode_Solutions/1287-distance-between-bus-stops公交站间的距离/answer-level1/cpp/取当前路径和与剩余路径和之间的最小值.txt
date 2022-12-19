### 解题思路
1. 统计所有路径和sum
2. 统计start~destination路径和总数
3. 取sum - cur与cur之间的最小值

### 代码

```cpp
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum = 0;
        if (start == 0 && destination == distance.size() - 1) {
            return distance.back();
        }

        for (auto n : distance) {
            sum += n;
        }
        
        int i = start, j = destination;
        if (start >= destination) {
            i = destination;
            j = start;
        }
        int cur = 0;
        while (i < j) {
            cur += distance[i];
            ++i;
        }
        return min(sum - cur, cur);
    }
};
```