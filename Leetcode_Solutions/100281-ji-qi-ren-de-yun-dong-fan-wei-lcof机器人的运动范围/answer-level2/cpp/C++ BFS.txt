### 解题思路
此处撰写解题思路
![2020-04-08 11-37-06 的屏幕截图.png](https://pic.leetcode-cn.com/4ae93af605b0489fd0865c0d6ff9290c42a7083b239a31442ee6e4438cfcd6cc-2020-04-08%2011-37-06%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

### 代码

```cpp
class Solution {
public:

    struct Coordinate {
        int x;
        int y;
    };

    int movingCount(int m, int n, int k) {

        int dx[] = {0, -1, 0, 1};
        int dy[] = {-1, 0, 1, 0};

        vector<vector<int>> visited(m, vector<int>(n, 0));

        queue<Coordinate> que;
        que.push({0, 0});
        visited[0][0] = 1;
        int ans = 1;

        while (!que.empty()) {
            auto coord = que.front();
            que.pop();

            for (int i = 0; i < 4; i++) {
                int nx = coord.x + dx[i];
                int ny = coord.y + dy[i];

                if (nx >=0 && nx < n && ny >=0 && ny < m) {
                    
                    if (visited[ny][nx]) continue;

                    int num = 0;
                    int temp = nx;

                    while (temp != 0) {
                        int x = temp % 10;
                        num += x;
                        temp = temp / 10;
                    }

                    temp = ny;
                    while (temp != 0) {
                        int y = temp % 10;
                        num += y;
                        temp = temp / 10;
                    }

                    if (num <= k) {
                        que.push({nx, ny});
                        visited[ny][nx] = 1;
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
```