### 解题思路
    /*
     * 模拟
     *
     * 先遍历棋盘，找到车的位置(row, col)，再模拟车的移动。因为车可以向东南西北四个方向移动，
     * 所以可以设置方向数组dx[4] = {1,0,-1,0}和dy[4] = {0,1,0,-1}，车按照步伐step对此四个方向进行遍历。
     * 如果遇到象则表示不能吃到对方的卒，退出当前遍历，继续其他方向；
     * 如果遇到对方的卒，则吃掉该卒，退出当前循环，继续其他方向。
     * */
### 代码

```cpp
int numRookCaptures(std::vector<std::vector<char>> &board) {
    if (board.empty()) {
        return 0;
    }

    int row = 0, col = 0;
    int ans = 0;

    // 找到车的位置
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'R') {
                // 车的行位置
                row = i;
                // 车的列位置
                col = j;
                break;
            }
        }
    }

    // 车移动的方向数组
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    // 遍历车移动的四个方向
    for (int i = 0; i < 4; i++) {
        // 车每次朝某个方向移动一个步伐
        for (int step = 1; step < 8; step++) {
            // 计算移动后车的新位置坐标
            int x = row + step * dx[i];
            int y = col + step * dy[i];

            // 判断遇到的是否为象
            if (x < 0 || x >= 8 || y < 0 || y >= 8 || board[x][y] == 'B') {
                break;
            }

            // 判断遇到的是否为卒
            if (board[x][y] == 'p') {
                ans++;
                break;
            }
        }
    }

    return ans;
}
```