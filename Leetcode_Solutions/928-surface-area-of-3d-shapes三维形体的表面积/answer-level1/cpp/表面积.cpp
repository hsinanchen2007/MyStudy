### 解题思路
此处撰写解题思路
### 别人的代码
一次遍历，计算每个柱体的左、上两个方向的重叠到最后就算出了所有重叠
不至于因计算上下左右四面而导致重复计算
```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size(), area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 先把grid[i][j]赋值给level，省掉了bound check，可以略微略微略微优化一下耗时。。。
                int level = grid[i][j];
                if (level > 0) {
                    // 一个柱体中：2个底面 + 所有的正方体都贡献了4个侧表面积 
                    area += (level << 2) + 2;
                    // 减掉 i 与 i-1 相贴的两份表面积
                    area -= i > 0? min(level, grid[i - 1][j]) << 1: 0; 
                    // 减掉 j 与 j-1 相贴的两份表面积
                    area -= j > 0? min(level, grid[i][j - 1]) << 1: 0;
                }  
            }
        }
        return area;
    }
};
```
### 我的代码
两次遍历时间耗费大
```
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int cover=0,sum=0;
        int len1=grid.size();
        int len2=grid[0].size();
        for(int i=0;i<len1;++i){
            for(int j=0;j<len2;++j){
                sum+=6*grid[i][j];
                if(grid[i][j]>1) cover+=grid[i][j]-1;
                if(j<len2-1){
                    cover+=min(grid[i][j],grid[i][j+1]);
                }
            }
        }
        for(int j=0;j<len2;++j){
            for(int i=0;i<len1;++i){
                if(i<len1-1){
                    cover+=min(grid[i][j],grid[i+1][j]);
                }
            }
        }
        sum-=cover*2;
        return sum;
    }
};
```
