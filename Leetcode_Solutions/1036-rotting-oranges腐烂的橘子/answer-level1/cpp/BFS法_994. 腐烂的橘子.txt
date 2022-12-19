### 解题思路
    /*
     * 广度优先遍历(BFS) O(m*n)
     *
     * 广度优先遍历通常使用队列进行处理，
     * 图中腐烂的橘子上下左右的橘子在一分钟后肯定会变成腐烂的橘子，
     * 那么原先腐烂的橘子就可以不再访问，只需要考虑刚刚腐烂的橘子，
     * 考虑到队列结构的特性，从最开始，可以把所有腐烂的橘子push到队列中，
     * 然后从队头依次弹出，并对该腐烂的橘子上下左右的橘子进行判断，
     * 如果一开始是新鲜橘子，就把该橘子腐烂，并push到队列的队尾，
     * 当第一轮腐烂的橘子遍历玩，就表示一分钟后，它们上下左右的新鲜橘子也腐烂了，
     * 并且这些腐烂的橘子也被push到队列中，进行下一轮的处理。
     * 这样只需要计数腐烂橘子的轮数即是所有橘子腐烂的分钟数。
     * 最后遍历结束，如果还有新鲜的橘子存在，表示这个橘子不可能腐烂，所以返回-1
     * */

### 代码
```cpp
int orangesRotting(std::vector<std::vector<int>> &grid) {
    // m 表示grid矩阵行数
    // n 表示grid矩阵列数
    int m = grid.size();
    int n = grid[0].size();

    int min = 0, fresh = 0;
    // BFS的结构适合使用队列
    std::queue<std::pair<int, int>> q;

    // 先遍历整个图获取新鲜的橘子数和腐烂的橘子
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 新鲜的橘子数用来判断是否有节点未遍历到，
            // 如果该节点未遍历到返回-1
            if (grid[i][j] == 1) {
                fresh++;
            } else if (grid[i][j] == 2) {
                // 将腐烂橘子全部push到队列中，再出队处理
                q.push(std::pair<int, int>(i, j));
            }
        }
    }

    // 当还有新鲜橘子并且存储腐烂橘子的队列不为空
    while (fresh > 0 && !q.empty()) {
        // min表示分钟数
        // 同时表示处理腐烂橘子的轮数
        min++;
        // 每一轮队列中腐烂橘子的个数
        int newRound = q.size();

        // 对队列中每个腐烂橘子的上下左右位置进行判断
        for (int i = 0; i < newRound; i++) {
            // 从队列头取一个腐烂的橘子
            std::pair<int, int> orange = q.front();
            q.pop();
            // row表示该腐烂橘子的横坐标，col表示纵坐标
            int row = orange.first;
            int col = orange.second;

            // 腐烂橘子的左边
            // 如果左边是新鲜橘子，则变为腐烂橘子
            // 同时新鲜橘子减一，并将该腐烂橘子push到新一轮队列中
            if (row - 1 >= 0 && grid[row - 1][col] == 1) {
                grid[row - 1][col] = 2;
                fresh--;
                q.push(std::pair<int, int>(row - 1, col));
            }

            // 腐烂橘子的右边
            if (row + 1 < m && grid[row + 1][col] == 1) {
                grid[row + 1][col] = 2;
                fresh--;
                q.push(std::pair<int, int>(row + 1, col));
            }

            // 腐烂橘子的下边
            if (col - 1 >= 0 && grid[row][col - 1] == 1) {
                grid[row][col - 1] = 2;
                fresh--;
                q.push(std::pair<int, int>(row, col - 1));
            }

            // 腐烂橘子的上边
            if (col + 1 < n && grid[row][col + 1] == 1) {
                grid[row][col + 1] = 2;
                fresh--;
                q.push(std::pair<int, int>(row, col + 1));
            }
        }
    }

    // 如果新鲜橘子数不等于0，
    // 表示有新鲜橘子的节点未遍历到
    if (fresh > 0) {
        return -1;
    }

    // 返回腐烂橘子队列的轮数
    return min;
}
```