### 解题思路

题目解析：可看成长度不同的长方柱体堆在一起。
柱体表面积由六面视图组成，上下前后左右，其中上下的表面积一样，所要求的就是柱体的前后左右的表面积
即判断柱体前后左右的邻接数，该柱体表面积为2（上下）+块数*4-邻接面数


### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int sum = 0;
		for(int i=0;i<grid.size();i++)
			for (int j = 0; j < grid[i].size(); j++)
			{
				//若是此处没有小块，则跳过
				if (grid[i][j] == 0)
					continue;
				sum += (2+grid[i][j]*4);//上下表面，块数
				//判断邻接面数,前后左右
				if (i + 1 < grid.size())
					sum -= min(grid[i][j], grid[i + 1][j]);
				if (i - 1 >= 0)
					sum -= min(grid[i][j], grid[i - 1][j]);
				if (j + 1 < grid[i].size())
					sum -= min(grid[i][j], grid[i][j + 1]);
				if (j - 1 < grid[i].size())
					sum -= min(grid[i][j], grid[i][j - 1]);
			}
		return sum;
    }
};
```