# 【极简思路】
**题目替换：**假设你拥有一个只能上下左右行走机器人，和一张有立着许多旗子（1）的地图（x轴向右👉为正，y轴👇为正），你需要调整几次机器人的位置将旗子全都推倒（0）。
**解体思路：**
首先，找到旗子的位置（x,y），判断场上是否还有旗子。
其次，从找到的旗子位置处（x,y）出发，放置机器人，让机器人从上下左右四个维度尽可能的推倒所有旗子。
最后，重复上述操作，推到地图上的所有旗子。
```
/* 检查地图上时候还有旗子（grid[y][x] == '1'），若有，则找到旗子，返回旗子的位置 */
bool check(char** grid, int gridSize, int* gridColSize, int* xRet, int* yRet) {
    for (int y = 0; y < gridSize; y++) {
        for (int x = 0; x < gridColSize[y]; x++) {
            if (grid[y][x] == '1') {
                *yRet = y;
                *xRet = x;
                return true;
            }
        }
    }
    return false;
}

/* 从上下左右四个维度尽可能的推倒所有旗子 */
void clearFlag(char** grid, int gridSize, int* gridColSize, int x, int y) {
    if (grid[y][x] == '0') { // 此处旗子如果已经推倒，则不做任何操作
        return;
    }       
    grid[y][x] = '0'; // 推倒旗子
    if (y - 1 >= 0) {
        clearFlag(grid, gridSize, gridColSize, x, y - 1); // 向上推倒下一个
    }
    if (x - 1 >= 0) {
        clearFlag(grid, gridSize, gridColSize, x - 1, y); // 向左推倒下一个
    }
    if (y + 1 < gridSize) {
        clearFlag(grid, gridSize, gridColSize, x, y + 1); // 向下推倒下一个
    }
    if (x + 1 < gridColSize[y]) {
        clearFlag(grid, gridSize, gridColSize, x + 1, y); // 向右推倒下一个
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int ans = 0;
    int x, y;
    while (check(grid, gridSize, gridColSize, &x, &y)) {
        clearFlag(grid, gridSize, gridColSize, x, y);
        ans++;
    }
    return ans;
}
```
**效率不一定最高，内存不一定最少，但希望最通俗易懂**