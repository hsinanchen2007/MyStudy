### 解题思路
int会溢出，为啥返回值不溢出呢

### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<long>> ob(obstacleGrid.size(),vector<long>(obstacleGrid[0].size(),0));
        if(!obstacleGrid.size())return 0;
        for(int i=ob.size()-1;i>=0;i--){
            for(int j=ob[0].size()-1;j>=0;j--){
                if(obstacleGrid[i][j])ob[i][j]=0;
                else if(i==ob.size()-1&&j==ob[0].size()-1)ob[i][j]=1;
                else {
                    long tx=(i==ob.size()-1?0:ob[i+1][j]),ty=(j==ob[0].size()-1?0:ob[i][j+1]);
                    ob[i][j]=tx+ty;
                }
            }
        }
        return ob[0][0];
    }
};
```