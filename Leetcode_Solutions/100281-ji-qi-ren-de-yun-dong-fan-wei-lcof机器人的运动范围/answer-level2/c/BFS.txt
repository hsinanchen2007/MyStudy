### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int> >vis(m, vector<int>(n, 0)); //创建之后并初始化位0
        int count = 0;
        int fx[4][2] = { -1,0,1,0,0,-1,0,1 };
        queue<pair<int, int> >qu;
        if (k >= 0) {
            qu.push(make_pair(0, 0));
            count++;
            vis[0][0] = 1;
        }
        int x, y, newx, newy;
        while (!qu.empty()) {
            x = qu.front().first;
            y = qu.front().second;
            qu.pop();
            for (int i = 0; i < 4; i++) {
                newx = x + fx[i][0];
                newy = y + fx[i][1];
                if (newx < 0 || newx >= m || newy < 0 || newy >= n || vis[newx][newy] || !check(newx, newy,k)) continue;
                qu.push(make_pair(newx, newy));
                count++;
                vis[newx][newy] = 1;
            }
        }
        return count;
    }
    bool check(int x, int y, int k) {
        int sum = 0;
        while (x) {
            sum += (x % 10);
            x /= 10;
        }
        while (y) {
            sum += (y % 10);
            y /= 10;
        }
        if (sum <= k) return true;
        else return false;
    }
};
```