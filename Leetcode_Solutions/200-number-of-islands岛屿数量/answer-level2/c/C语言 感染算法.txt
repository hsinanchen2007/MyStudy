### 解题思路

遇岛则进行感染

![image.png](https://pic.leetcode-cn.com/3f3f18b35c5d68c1f3f011422070630a1cb413d34458f4bd19b99cc29d3fcb39-image.png)

### 代码

```c
#define MY_NUM_1 '1'
#define MY_NUM_0 '0'
#define MY_NUM_2 '2'

typedef struct {
    char **grid;
    int gridSize;
    int *gridColSize;
} MyStatus;

bool posIsValid(MyStatus *s, int x, int y)
{
    if (x < 0 || y < 0 || x >= s->gridSize || y >= s->gridColSize[0]) {
        return false;
    }
    return true;
}

void infect(MyStatus *s, int x, int y) 
{
    if (posIsValid(s, x, y) == false) {
        return;
    }
    if (s->grid[x][y] != MY_NUM_1) {
        return;
    }
    s->grid[x][y] = MY_NUM_2;
    infect(s, x + 1, y);
    infect(s, x - 1, y);
    infect(s, x, y + 1);
    infect(s, x, y - 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int i, j;
    int cnt = 0;
    MyStatus s;
    s.grid = grid;
    s.gridSize = gridSize;
    s.gridColSize = gridColSize;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] != MY_NUM_1) {
                continue;
            }
            cnt++;
            infect(&s, i, j);
        }
    }
    return cnt;
}
```