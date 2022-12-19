### 解题思路
分三步：
（1）先找出有效的1的个数；（2）按行查找相邻的1个数，如第一行，从第1列到最后1列相邻1的个数记录下来，代表着左右会有多少个边长会被减掉（从左向右找）；（3）按列查找相邻1的个数（从上向下找），与第（2）步类似；最后得出周长数值为有效1的个数*4-相邻数*2，即为最后结果。执行结果： 通过 显示详情  执行用时 : 88 ms , 在所有 c 提交中击败了 96.19% 的用户 内存消耗 : 10.1 MB , 在所有 c 提交中击败了 100.00% 的用户

### 代码

```c
int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int i;
    int j;
    int cnt = 0;
    int cntValid = 0;
    int result = 0;

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1) {
                cntValid++;
            }
        }
    }

    // from left to right
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < *gridColSize - 1; j++) {
            if (grid[i][j] == 0) {
                continue;
            } else {
                if (grid[i][j + 1] == 0) {
                    continue;
                } else {
                    cnt++;
                }
            }
        }
    } 

    // from up to down
    for (j = 0; j < *gridColSize; j++) {
        for (i = 0; i < gridSize - 1; i++) {
            if (grid[i][j] == 0) {
                continue;
            } else {
                if (grid[i + 1][j] == 0) {
                    continue;
                } else {
                    cnt++;
                }
            }
        }
    }

    result = cntValid * 4 - cnt* 2;

    return result;
    
}
```