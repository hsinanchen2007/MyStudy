### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/41218b1697b8b3681256e437e984ed950646fcc992d750d4456fba132cca00e6-image.png)

### 代码

```c
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int ans = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            int v = grid[i][j];
            int left, right, up, down;
            left = right = up = down = 0;

            if (v > 0) {
                ans += 2;

                if (i - 1 < 0) {
                    ans += v;
                }
                if (j + 1 >= gridColSize[i]) {
                    ans += v;
                }
                if (j - 1 < 0) {
                    ans += v;
                }
                if (i + 1 >= gridSize) {
                    ans += v;
                }

                //left
                if (j - 1 >=0) {
                    left = grid[i][j - 1];
                    ans += (v - left) > 0 ? (v - left) : 0;
                }
                if (j + 1 < gridColSize[i]) {
                    right = grid[i][j + 1];
                    ans += (v - right) > 0 ? (v - right) : 0;
                }
                if (i - 1 >= 0) {
                    up = grid[i - 1][j];
                    ans += (v - up) > 0 ? (v - up) : 0;
                }
                if (i + 1 < gridSize) {
                    down = grid[i + 1][j];
                    ans += (v - down) > 0 ? (v - down) : 0;
                }
            }
        }
    }

    return ans;
}
```