// ### 解题思路一 暴力遍历
//     /*
//      * 暴力遍历 超时 O(n2)
//      *
//      * 先将矩阵中的陆地点(1)和海洋点(0)找到后分别存储到数组中。
//      * 再以海洋点数组为源点集，找到每个海洋点到陆地点的最小距离，
//      * 而每个海洋点的最小距离中的最大值就是海洋区域和所有陆地区域之间的距离最大值。
//      * */
// ### 代码

// ```cpp
int maxDistance(std::vector<std::vector<int>> &grid) {
    if (grid.empty()) {
        return -1;
    }

    std::vector<std::pair<int, int>> land;
    std::vector<std::pair<int, int>> ocean;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                land.emplace_back(i, j);
            }

            if (grid[i][j] == 0) {
                ocean.emplace_back(i, j);
            }
        }
    }

    if (ocean.empty() || land.empty()) {
        return -1;
    }

    int ans = 0;

    for (auto &i : ocean) {
        int temp = INT_MAX;
        for (auto &j : land) {
            temp = std::min(temp, std::abs(i.first - j.first) + std::abs(i.second - j.second));
        }

        ans = std::max(ans, temp);
    }

    return ans;
}
// ```

// ### 解题思路二 多源最短路径 -- BFS
// 来自甜姨的答案[🌊简单Java, 秒懂图的BFS～](https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/jian-dan-java-miao-dong-tu-de-bfs-by-sweetiee/)


//     /*
//      * 多源最短路径--BFS O(n2)
//      *
//      * 能够使用BFS求最短路径,将所有陆地点入队，再以各个陆地点为源点，
//      * 同时开始一层一层的向海洋扩散，最后扩散到的海洋就是最远的海洋。
//      * */
// ### 代码

// ```cpp
int maxDistance(std::vector<std::vector<int>> &grid) {
    if (grid.empty()) {
        return -1;
    }

    int rows = grid.size();
    int cols = grid[0].size();

    // 扩散的四个方向
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    // 存储陆地源点的队列
    std::queue<std::pair<int, int>> que;

    // 将每个陆地源点入队
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                que.push(std::make_pair(i, j));
            }
        }
    }

    // 从各个陆地开始，一层一层的遍历海洋，
    // 最后遍历到的海洋就是最远海洋
    bool hasOcean = false;
    std::pair<int, int> point(0, 0);
    while (!que.empty()) {
        // 取队首元素
        point = que.front();
        que.pop();
        int x = point.first;
        int y = point.second;

        // 从该源点开始的四个方向遍历海洋
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX < 0 || newX >= rows || newY < 0 || newY >= cols || grid[newX][newY] != 0) {
                continue;
            }

            // 修改原数组，避免重复遍历，
            // 且每次增加1表示距离陆地的距离
            grid[newX][newY] = grid[x][y] + 1;
            hasOcean = true;
            // 将其四周的海洋入队
            que.push(std::make_pair(newX, newY));
        }
    }

    // 如果只有陆地或只有海洋时返回-1
    if (!hasOcean) {
        return -1;
    }

    // 最远海洋到陆地的距离
    return grid[point.first][point.second] - 1;
}
// ```