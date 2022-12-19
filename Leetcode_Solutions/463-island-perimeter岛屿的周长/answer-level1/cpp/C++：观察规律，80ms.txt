思路：遍历每个方块，先统计每个方块四周有多少个方向有“陆地”，然后拿4减去，就得到了每个方块为周长“所作的贡献”。
```
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        //sum记录周长
        //count记录每个方格四周邻接的“陆地”数目（即内边）
        int sum = 0, count;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                //清零
                count = 0;
                if(grid[i][j] == 1){
                    count += (i-1>=0 && grid[i-1][j]==1);              //上
                    count += (j-1>=0 && grid[i][j-1]==1);              //左
                    count += (i+1<grid.size() && grid[i+1][j]==1);     //下
                    count += (j+1<grid[0].size() && grid[i][j+1]==1);  //右
                    //4-count得外边数
                    sum += 4-count;
                }
            }
        }
        return sum;
    }
};
```
