第26行，从队列里取出一个状态后也还是要判断这个状态的可用性。

```C++
class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> vec;
        for (size_t i = 0; i < land.size(); ++i) {
            for (size_t j = 0; j < land[0].size(); ++j) {
                if (land[i][j] == 0) {
                    vec.push_back(bfs(land, i, j));
                }
            }
        }
        sort(vec.begin(), vec.end());
        return vec;
    }

    int bfs(vector<vector<int>> &land, int i, int j) {
        if (i == 11 && j == 48) {
            cout << "foo bar";
        }
        queue<pair<int, int>> que;
        que.push(pair<int,int>{i, j});
        int area = 0;
        while (!que.empty()) {
            auto pond = que.front();
            que.pop();
            if (land[pond.first][pond.second] != -1) {
                ++area;
            }
            land[pond.first][pond.second] = -1;
            for (auto d : direction) {
                if (available(land, pond.first + d[0], pond.second + d[1])) {
                    que.push(pair<int,int>{pond.first + d[0], pond.second + d[1]});
                }
            }
        }
        return area;
    }

    inline bool available(vector<vector<int>> &land, int i, int j) {
        return i >= 0 && i < land.size() && j >= 0 && j < land[0].size() && land[i][j] == 0;
    }
private:
    int direction[9][2] = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
    };
};
```