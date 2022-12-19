### 解题思路
其实题意很简单，不要输入中每个数字就是一个`grid[i][j]`值，如`[[1,2],[3,4]] `中的`1`就是`grid[0][0]=1`
```
[[1,2],[3,4]]        [[1,1,1],[1,0,1],[1,1,1]]
   grid[i][j]              grid[i][j]
      0 1                    0 1 2
   0 |1|2|                0 |1|1|1|
   1 |3|4|                1 |1|0|1|
                          2 |1|1|1|

逐个grid[i][j]位置遍历,再逐个柱体在k=1->grid[i][j]上，由下到上遍历；
其中每一层的每个方块都依次判断与周围四个方向相邻柱体高度的大小，即grid[i][j]的值；
如果k>周围四个方向grid[i][j],则增加面积；
注意i == 0,j == 0,i == grid.size() - 1,j == grid[i].size() - 1的情况，即位于外沿的柱体。
```

### 代码

```cpp
//用的比较笨的方法
class Solution {
   public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = 0;
        int s = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] > 0) {
                    n++;
                    int mark = 0;
                    for (int k = 1; k <= grid[i][j]; k++) {
                        if (i > 0 && k > grid[i - 1][j]) {
                            mark++;
                        }
                        if (i < grid.size() - 1 && k > grid[i + 1][j]) {
                            mark++;
                        }
                        if (j > 0 && k > grid[i][j - 1]) {
                            mark++;
                        }
                        if (j < grid[i].size() - 1 && k > grid[i][j + 1]) {
                            mark++;
                        }
                        if (i == 0) {
                            mark++;
                        }
                        if (i == grid.size() - 1) {
                            mark++;
                        }
                        if (j == 0) {
                            mark++;
                        }
                        if (j == grid[i].size() - 1) {
                            mark++;
                        }
                    }
                    s += mark;
                }
            }
        }
        return s + 2 * n;
    }
};
```