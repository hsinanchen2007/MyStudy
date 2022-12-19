### 解题思路
遍历，找到有几个面互相重叠，用总面积减去即可
![image.png](https://pic.leetcode-cn.com/3a368d06fcb195df9d686ac496c3a489652852e1de62b8804d240bf9babcbb1a-image.png)


### 代码

```c
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int sum = 0;
    int i, j;
    int n1 = 0, n2 = 0, n3 = 0;

    for(i = 0; i < gridSize; i++) {
        for(j = 0; j < gridSize; j++) {
            sum += grid[i][j];
            if(grid[i][j]) {
                n1 = n1 + (grid[i][j] - 1);
            }
        }
    }

    for(i = 0; i < gridSize; i++) {
        for(j = 0; j < gridSize - 1; j++) {
            n2 = n2 + fmin(grid[i][j], grid[i][j + 1]);
        }
    }

    for(j = 0; j < gridSize; j++) {
        for(i = 0; i < gridSize - 1; i++) {
            n3 = n3 + fmin(grid[i][j], grid[i + 1][j]);
        }
    }

    printf("sum = %d, n1 = %d, n2 = %d, n3 = %d", sum, n1, n2, n3);
    return sum * 6 - (n1 + n2 + n3) * 2;
}
```