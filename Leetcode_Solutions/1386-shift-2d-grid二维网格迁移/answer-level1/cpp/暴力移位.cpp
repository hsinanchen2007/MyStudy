//思路就是循环k次，每次移动一个数，用next保存上一个被替换的数，初始化next为最后一个数，
//遍历第一个就是先存储1， 然后把原来是1的数存储为next的值，也就是9，最后将next赋值为替换掉的数也就是1 
// temp 保存1， grid[i][j] = next(9); next = temp; 
//每循环一次next重新初始化为最后一个数
//第一个将1位置变成9， 存储1， 第二次将2位置变成1，存储2， 以此类推 ,不用考虑当前位置
```
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();       //m行
        int n = grid[0].size();    //n列
        int next = grid[m-1][n-1],temp;
        //挪动的次数
        for(int t = 0; t<k; t++) {
            for(int i = 0; i<m; i++) {
                for(int j =0; j<n; j++) {
                    //暂存当前数
                    temp = grid[i][j];
                    //将当前数赋值给上一个数也就是把2位置赋值给1
                    grid[i][j] = next;
                    //将当前数赋值给next  也就是保存2，
                    next = temp;
                }
            }
            next = grid[m-1][n-1];
        }
        return grid;
    }
```