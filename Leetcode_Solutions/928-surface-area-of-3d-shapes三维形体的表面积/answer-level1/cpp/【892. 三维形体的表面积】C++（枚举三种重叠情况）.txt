### 解题思路：枚举
首先，理解题意。
题目的输入是二维数组，代表N*N的网格中每个格子上的正方体数目；输出是这些正方体放在一起的表面积。
解题思路：枚举正方体表面出现重叠的情况；
1. 垂直方向：每个格子上叠加向上垒起来，重叠表面个数=（正方体个数-1）*2；
2. 行方向：遍历整个网格，与左侧格子的正方体对比，重叠表面个数=min（i-1上正方体个数，i上正方体个数）*2；
3. 列方向：遍历整个网格，与上面格子的正方体对比，重叠表面个数=min（j-1上正方体个数，j上正方体个数）*2；
**注意：行方向和列方向要判断边界`i>0`和`j>0`，因为边界格子侧面不会重叠**
**小Tips：** 在循环中，每次逐类判断前先赋值`m = grid[i][j]`，减少调用vector数组的次数，优化时间。
![image.png](https://pic.leetcode-cn.com/d22827b2c17e7f7a1efa4ec2427ab90d92b5554dd35ebad9dcf9aa8f76de3ac0-image.png)


### 代码

```cpp []
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                int m = grid[i][j];
                if(m>0){
                    res += m*6 - (m-1) *2;
                    if(i>0)
                        res -= min(grid[i-1][j], m)*2;
                    if(j>0)
                        res -= min(grid[i][j-1], m)*2;
                }
            }
        }
        return res;
    }
};
```

```cpp []
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]>0){
                    res += grid[i][j]*6 - (grid[i][j]-1) *2;
                    if(i>0)
                        res -= min(grid[i-1][j], grid[i][j])*2;
                    if(j>0)
                        res -= min(grid[i][j-1], grid[i][j])*2;
                }
            }
        }
        return res;
    }
};
```