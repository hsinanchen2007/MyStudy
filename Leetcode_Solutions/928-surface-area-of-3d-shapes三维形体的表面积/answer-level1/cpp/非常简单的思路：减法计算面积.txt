很简单的思路：首先计算所有方块的面积和，然后减去堆叠后的重叠部分，通过横、纵两个方向来减。

```
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) 
    {
        int sum = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.at(i).size();j++)
            {
                int value = grid.at(i).at(j);
                // 1.计算所有面积和（四周+上下）
                sum += 4*value + (value?2:0);
                // 2.减去横向重叠部分
                sum -= i>0? 2*min(value,grid.at(i-1).at(j)):0;
                // 3.减去纵向重叠部分
                sum -= j>0? 2*min(value,grid.at(i).at(j-1)):0;
            }
        }
        return sum;
    }
};
```
