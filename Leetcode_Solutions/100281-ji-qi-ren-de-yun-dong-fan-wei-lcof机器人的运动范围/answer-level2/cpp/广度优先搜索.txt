### 解题思路
广度优先搜索，从0点开始向四个方向进行广度优先搜索。

### 代码

```cpp
class Solution {
private:
    int get(int x) {
        int res = 0;
        while( x > 0) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }
public:
    int movingCount(int m, int n, int k) {
        if (!k) return 1;
        queue<pair<int,int> > Q;
        int d[4][2] = {{0, 1},{1, 0},{0, -1},{-1, 0}};
        vector<vector<int> > visted(m, vector<int>(n, 0));
        Q.push(make_pair(0, 0));
        visted[0][0] = 1;
        int ans = 1;
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();
            for (int i = 0; i < 4; ++i) {
                int tx = d[i][0] + x;
                int ty = d[i][1] + y;
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || visted[tx][ty] || get(tx) + get(ty) > k) 
                    continue;
                Q.push(make_pair(tx, ty));
                visted[tx][ty] = 1;
                ans++;
            }
        }
        return ans;
    }

};
```