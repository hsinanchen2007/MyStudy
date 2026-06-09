维护一个动态的水池边界点集，初始化为{{0,1},{1,0}}；
不断加高水位，水位打到水池边界最低点，则更新水池边界点集，往外扩张

```
    bool** MakeMatrix(int rows, int cols, bool defVal) {
        bool** mat = new bool*[rows];
        for (int i = 0; i < rows; ++i) {
            mat[i] = new bool[cols];
            fill_n(mat[i], cols, false);
        }
        return mat;
    }

    void DestroyMatrix(bool** mat, int rows) {
        for (int i = 0; i < rows; ++i) {
            delete[] mat[i];
        }
        delete[] mat;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        bool** gridUsed = MakeMatrix(N, M, false);
        int level = grid[0][0];
        gridUsed[0][0] = true;
        list<vector<int>> border;  // 动态的水池边界点集: 初始化为{{0,1},{1,0}}
        border.push_back({0,1});
        border.push_back({1,0});
        gridUsed[0][1] = true;
        gridUsed[1][0] = true;
        while (border.size() < (M * N)) {
            auto it = border.begin();
            bool expanded = false;  // 标记水池边界是否有变化，若无变化则需要加高水位
            int minBorder{INT_MAX}; // 记录水池边界的最低高度
            while (it != border.end()) {
                int x = (*it)[0];
                int y = (*it)[1];
                if (x == M - 1 && y == N - 1 && grid[x][y] <= level) {
                    goto RET; // 已达到右下角点，成功返回。
                }
                minBorder = min(minBorder, grid[x][y]);
                if (grid[x][y] <= level) {  // 水池边界点不高于水位，则把水淹过去，更新边界集
                    it = border.erase(it);  // 删除淹掉的边界点
                    // add new border.
                    if (++x < N && !gridUsed[x][y]) {
                        border.push_back({x,y});
                        gridUsed[x][y] = true;
                        expanded = true;
                    }
                    --x;
                    if (++y < M && !gridUsed[x][y]) {
                        border.push_back({x,y});
                        gridUsed[x][y] = true;
                        expanded = true;
                    }
                    --y;
                    if (--x >= 0 && !gridUsed[x][y]) {
                        border.push_back({x,y});
                        gridUsed[x][y] = true;
                        expanded = true;
                    }
                    ++x;
                    if (--y >= 0 && !gridUsed[x][y]) {
                        border.push_back({x,y});
                        gridUsed[x][y] = true;
                        expanded = true;
                    }
                } else {
                    ++it;
                }
            }
            if (!expanded) {
                level = minBorder;
            }
        }
RET:
        DestroyMatrix(gridUsed, N);
        return level;
    }
```
![image.png](https://pic.leetcode-cn.com/58ef580eaf73dc431e1109d3540282b2eee1e8fed7f0f6684d5b0ad1cf2afbaf-image.png)
