### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/910a2316e5f73b4b86f245007650531f78eb2a61ada90394e125e075f9fa341e-%E6%8D%95%E8%8E%B7.PNG)
首先解决坐标数位之和小于k的问题，然后采用广度优先遍历算法逐个遍历，注意记录各个坐标位置是否已访问，否则可能会陷入无限循环。

### 代码

```cpp
class Solution {
public:
    int digitSum(int n)
    {
        int d_sum = 0;
        while (n > 0)
        {
            int mod = n % 10;
            d_sum += mod;
            n /= 10;
        }
        return d_sum;
    }

    int movingCount(int m, int n, int k)
    {
        if (m == 0 && n == 0) return 0;
        if (k == 0) return 1;
        int range = 1;
        vector<pair<int, int>> dirs = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({ 0, 0 });
        visited[0][0] = true;
        while (!q.empty())
        {
            auto qf = q.front();
            q.pop();
            for (auto dir : dirs)
            {
                int x = qf.first + dir.first;
                int y = qf.second + dir.second;
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y])
                {
                    int dSum = digitSum(x) + digitSum(y);
                    if (dSum <= k)
                    {
                        q.push({ x, y });
                        range++;
                        visited[x][y] = true;
                    }
                }
            }
        }
        return range;
    }
};
```