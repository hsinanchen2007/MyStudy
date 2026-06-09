### 解题思路

1. 先遍历数组，如果为2且相邻为1，则将相邻的数变为2，并用flag来标记说明有新的腐坏的橘子，说明下次还要再遍历。
2. flag有变化，则minute也加1.
3. 最后完成循环之后，再看看数组中有没有值为1的元素，有则返回-1，否则返回时间数

### 代码

```cpp
class Solution {
public:

    // 如果全部完成之后数组中还有值是等于1的，那么返回-1，否则返回时间数

    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> gd2;
        gd2 = grid;
        
        int flag = 1, minute = 0;
        
        while(flag){
            flag = 0;
            for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid[i].size(); j++){
                    if(grid[i][j]==2){
                        if( (i!=0) && grid[i-1][j] == 1 ){
                            gd2[i-1][j] = 2;		// up
                            flag++;
                        }
                        if( (i!=grid.size()-1) && grid[i+1][j] == 1 ){
                            gd2[i+1][j] = 2; 	// down
                            flag++;
                        }
                        if( (j!=0) && grid[i][j-1] == 1 ){
                            gd2[i][j-1] = 2;		// left
                            flag++;
                        }
                        if( (j!=grid[i].size()-1) && grid[i][j+1] == 1 ){
                            gd2[i][j+1] = 2;	// right
                            flag++;
                        }
                    }
                }
            }
            if(flag) minute++;
            grid = gd2;
        }

        for(int i = 0; i < gd2.size(); i++)
            for(int j = 0; j < gd2[i].size(); j++)
                if(gd2[i][j]==1) minute = -1;

        return minute;

    }
};


```