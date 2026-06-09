使用累加法计算
v = grid[i][j]
1、如果v大于0，那么会提供底面和顶面的表面积，+2。
2、分别与上下左右的值比较，如果差值为正则加上差值，否则加0。
```
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int size = grid.size();
        int count = 0;
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                int v = grid[i][j];
                if(v != 0)
                    count += 2;
                if(i == 0)
                    count += v;
                else
                    count += max(v-grid[i-1][j],0);
                if(i == size - 1)
                    count+= v;
                else
                    count += max(v-grid[i+1][j],0);
                if(j == 0)
                    count += v;
                else
                    count += max(v-grid[i][j-1],0);
                if(j == size-1)
                    count += v;
                else
                    count += max(v-grid[i][j+1],0);
            }
        }
        return count;
    }
};
```