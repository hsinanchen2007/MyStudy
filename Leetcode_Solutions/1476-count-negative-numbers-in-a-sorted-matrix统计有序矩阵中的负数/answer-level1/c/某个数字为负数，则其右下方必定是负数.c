### 解题思路
![image.png](https://pic.leetcode-cn.com/815903090dd7a2fa2d8cf55e871c8abb899ee937e8b7198cb6f192db5fba0342-image.png)

从右上角开始，找到每一列的负数起始位置；
如果当前为正数，往下移动；如果为负数，累加，并往左移动

### 代码

```c

int countNegatives(int** grid, int gridSize, int* gridColSize){
    int sum = 0;
    int columnK = gridColSize[0];
    int height = 0;

    while (columnK) {
        height = 0;
        while ((grid[height][columnK - 1] >= 0)) {
            height++;  // 往下一直走，直到遇到负数
            if (height >= gridSize) {
                break;
            }
        }
        if (height < gridSize) {  // 往下还没有走到底，说明确实遇到了负数，计算并往左走
            sum += (gridSize - height);
        }
        columnK--;
    }
    return sum;
}
```