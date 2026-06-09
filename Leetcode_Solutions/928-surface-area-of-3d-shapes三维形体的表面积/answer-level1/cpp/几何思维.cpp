### 解题思路
这道题目其实很简单，主要分为两个步骤：
- 算出每一个格子上的堆叠立方体的表面积
- 算出重叠部分的面积

首先算每一个格子的堆叠立方体的表面积:
$$ S = 2 + N * 4 ,\quad s.t \quad N > 0 $$
但是，立方体会存在堆叠的情况。
我们知道堆叠的肯定是相邻的立方体间最小个数的面。
假设当前格子的立方体数为$a$，相邻格子的立方体数为$b$,则：
$$ S_O = 2 * \min(a,b) $$
这样，遍历整个方格，就可以得到最终的表面积了:
$$S_F = S - S_O $$


### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        //每一个网格的表面积：2 + N * 4;
        //再算有多少个相邻面。
        int whole_area = 0;
        int overlap_area = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] != 0) whole_area += 2 + grid[i][j]*4;
                if(j > 0) overlap_area += 2 * min(grid[i][j], grid[i][j-1]);
            }
        }
        cout << overlap_area << endl;
        for(int i = 0; i < grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                if(j > 0) overlap_area += 2 * min(grid[j][i], grid[j-1][i]);
            }
        }
        cout << whole_area << " " << overlap_area << endl;
        return whole_area - overlap_area;
    }
};
```