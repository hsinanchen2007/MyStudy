### 解题思路
弱鸡的题解：
我的想法就是 先想右走，走不通就向下走。如果右和下同时走不通，就把这个点记为障碍，再从上个点继续走。
每次走的时候要判断是否能走通（起点终点不能为障碍）

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> res;
        int c=size(obstacleGrid[0]);
        int r=size(obstacleGrid);
        int i=0,j=0;
        if (obstacleGrid[0][0] == 1 || obstacleGrid[r - 1][c - 1] == 1)
            return res;
        res.push_back({i,j});

        while(i!=r-1 || j!=c-1)
        {
            if (obstacleGrid[0][0] == 1 || obstacleGrid[r - 1][c - 1] == 1) return {};                     
            if(j+1<=c-1)
            {
                if(obstacleGrid[i][j+1]==0)
                {
                    j=j+1;
                    res.push_back({i,j});
                    continue;
                }
            }

            if(i+1<=r-1)
            {
                if(obstacleGrid[i+1][j] == 0)
                {
                    i=i+1;
                    res.push_back({i,j});
                    continue;
                }
            }

            obstacleGrid[i][j]=1;
            res.pop_back();

            int r1=size(res);
            if(r1<1){
                i=0;
                j=0;
            }
            else
            {
                i=res[r1-1][0];
                j=res[r1-1][1];
            }
        }

        return res;
    }
};
```