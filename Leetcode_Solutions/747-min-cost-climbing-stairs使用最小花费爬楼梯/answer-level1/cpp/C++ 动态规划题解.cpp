### 代码

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int c1 = cost[0];
        int c2 = cost[1];
        int N = cost.size();
        for (int i = 2; i < N; ++i) {
            int c3 = min(c1, c2) + cost[i];
            c1 = c2;
            c2 = c3;
        }
        return min(c1, c2);
    }
};
```

![image.png](https://pic.leetcode-cn.com/139c5b0d8e1287dd2accfc38d5696cc72945a7bc0d3d7b1c6005acc6a3d870f0-image.png)
