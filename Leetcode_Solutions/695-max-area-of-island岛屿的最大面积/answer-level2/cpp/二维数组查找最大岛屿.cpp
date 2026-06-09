### 解题思路
题目意思是查找数组中1相邻且相邻的1数的和最大的地方
考察深度遍历和广度遍历。细节的话注意建立一个索引数组方便代码的简洁书写。以及设成0后不会再次重复遍历某个岛屿区域

### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows=grid.size();
        cols = grid[0].size();
        int ans=0;
        for (int i =0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                ans = max(ans,singleCore(grid,i,j));
            }
        }
        return ans;
    }
private:
    int rows=0;
    int cols=0;
    int rowBound[4] = {0,0,1,-1};
    int colBound[4] = {1,-1,0,0};
    int singleCore(vector<vector<int>>& grid,int row , int col){
        if (row<0 || col<0 || row==rows ||col == cols || grid[row][col] != 1){
            return 0;
        }
        int ans=1;
        grid[row][col] = 0;
        for(int i=0;i<4;i++){
            ans += singleCore(grid,row+rowBound[i],col+colBound[i]);
        }
        return ans;
    }
};
```