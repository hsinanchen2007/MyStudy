### 解题思路
一边求单个格子中累加的正方体表面积 公式为：4 * 格子中正方体数量 + 2
一边减去相邻格子导致减少的表面积 假设格子1和格子2相邻， 则减去 min(格子1正方体数量，格子2正方体数量) * 2

### 代码

```cpp
class Solution {
public:

    int surfaceArea(vector<vector<int>>& grid) {

        int area = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid.at(i).size(); ++j)
            {
                if(grid.at(i).at(j) > 0) //单个格子中累加的表面积
                {
                    area += 4 * grid.at(i).at(j) + 2;
                }

                //找出相邻的
                if(j > 0)
                {
                    if (grid.at(i).at(j - 1) > 0 && grid.at(i).at(j) > 0) //横向比较 存在相邻
                    {
                        area -= min(grid.at(i).at(j - 1), grid.at(i).at(j)) * 2;
                    }

                    if (grid.at(j - 1).at(i) > 0 && grid.at(j).at(i) > 0) //纵向比较 存在相邻
                    {
                        area -= min(grid.at(j - 1).at(i), grid.at(j).at(i)) * 2;
                    }
                }
            }
        }

        return area;
    }
};
```