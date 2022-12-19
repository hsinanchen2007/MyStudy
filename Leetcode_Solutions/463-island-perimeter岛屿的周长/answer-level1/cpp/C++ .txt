![image.png](https://pic.leetcode-cn.com/0e3dd5c8b3b0ded06b295d8959f33146b8d3e2f9e311d4e6dbb36f30aa5ec0b3-image.png)
解题思路：统计数组中1的个数count，返回2*count+2。若四个一组成方块--count。
```
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0;
        for(int i = 0;i<grid.size();++i)
        for( int j =0;j<grid[0].size();++j) 
            if(grid[i][j] == 1) ++count;
        for(int i = 0;i<grid.size()-1;++i)
        for( int j =0;j<grid[0].size()-1;++j)
        if(grid[i][j] == 1 && grid[i][j+1] == 1 &&grid[i+1][j] == 1 && grid[i+1][j+1] == 1)
        --count;
        return 2*count+2;
    }
```
