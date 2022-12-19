### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        //记录已经访问过的点
        vector<vector<int>> graph(m, vector<int>(n));

        int ans = 0;
        int x[4] = {1,0,-1,0};
        int y[4] = {0,1,0,-1};

        queue<pair<int, int>> que;
        que.push({0,0});
        graph[0][0] = 1;
        ans = 1;
        while(!que.empty())
        {
            auto temp = que.front();
            que.pop();

            for(int i = 0; i < 4; ++i)
            {
                int xn = temp.first + x[i];
                int yn = temp.second + y[i];

                if(xn < 0 || xn >= m || yn < 0 || yn >= n || graph[xn][yn] == 1 ||canReach(xn,yn) > k) continue;
                graph[xn][yn] = 1;
                ans++;
                que.push({xn,yn});
            }
        }

        return ans;
    }

    int canReach(int m, int n)
    {
        int cnt = 0;
        while(m != 0)
        {
            cnt += m % 10;
            m = m / 10;
        }

        while(n != 0)
        {
            cnt += n % 10;
            n = n / 10;
        }

        return cnt;
    }
};
```