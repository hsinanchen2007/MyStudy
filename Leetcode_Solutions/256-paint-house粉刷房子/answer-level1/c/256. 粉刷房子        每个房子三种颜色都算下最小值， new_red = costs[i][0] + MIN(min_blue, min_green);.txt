### 解题思路
动态规划思想，  遍历每个房子。 每个房子都算下到当前时，选红 蓝 绿三种颜色的最小值
new_red = costs[i][0] + MIN(min_blue, min_green);
new_blue = costs[i][1] + MIN(min_red, min_green);
new_green = costs[i][2] + MIN(min_red, min_blue);


假如有一排房子，共 n 个，每个房子可以被粉刷成红色、蓝色或者绿色这三种颜色中的一种，你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。

当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。每个房子粉刷成不同颜色的花费是以一个 n x 3 的矩阵来表示的。

例如，costs[0][0] 表示第 0 号房子粉刷成红色的成本花费；costs[1][2] 表示第 1 号房子粉刷成绿色的花费，以此类推。请你计算出粉刷完所有房子最少的花费成本。

注意：

所有花费均为正整数。

示例：

输入: [[17,2,17],[16,16,5],[14,3,19]]
输出: 10
解释: 将 0 号房子粉刷成蓝色，1 号房子粉刷成绿色，2 号房子粉刷成蓝色。
     最少花费: 2 + 5 + 3 = 10。

### 代码

```c
#define MIN(a,b) ((a)<(b)?(a):(b))

int minCost(int** costs, int costsSize, int* costsColSize){
    int min_red=0, min_blue=0, min_green=0;
    int i, new_red, new_blue, new_green;

    //if(costsSize == 0)  return 0;
    //min_red = costs[0][0];
    //min_blue = costs[0][1];
    //min_green = costs[0][2];
    for (i = 0; i < costsSize; i++){
        new_red = costs[i][0] + MIN(min_blue, min_green);
        new_blue = costs[i][1] + MIN(min_red, min_green);
        new_green = costs[i][2] + MIN(min_red, min_blue);
        min_red = new_red;
        min_blue = new_blue;
        min_green = new_green;
    }
    return MIN(MIN(min_red, min_blue), min_green);
}
```