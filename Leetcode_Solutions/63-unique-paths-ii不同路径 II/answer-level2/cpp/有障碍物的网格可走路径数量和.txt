### 解题思路
首先网格型的题应该注意是否可以转成动态规划题，如果是动规的话，第一行和第一列是不是是可快速得到的值，首先求出来
然后再在dp[1][1]开始遍历
此题的状态量是第i,j个格子数处可得到的最大路径，如果该格是1则置0，不是的话则dp[i][j]=dp[i][j-1]+ dp[i-1][j]
此题还比较坑的一点是，在某sqrt(int)*sqr(int)网格大小时dp数据类型为Int时会溢出，所以本来官网给的占内存更小的方法是直接用obstacleGrid当dp，空间复杂度就为O(1)，但是由于会溢出
必须得单独设置一个dp数组，注意二维dp数组初始化
vector<vector<int> > vect(vt);//使用另一个二维vt初始化当前二维vector
vector< vector<int> > vec(row,vector<int>(column));//初始化一个二维的vector 行row,列column,且值为0
vector<vector<int> > visited(row,vector<int>(column,6));//初始化一个 二维vector 行row,列column ,且值为6;
vector<vector<int> > vecto(row,vector<int>(vt[0].begin()+1,vt[0].begin()+3));////初始化一个二维vector行为row,col为一维vt前三个元素;

### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())
            return 0;
        vector<vector<long>> dp (obstacleGrid.size(),vector<long>(obstacleGrid[0].size(),0));
        if(obstacleGrid[0][0] == 1){
            dp[0][0]=0;
        }
        else{
            dp[0][0]=1;
        }
        for(int i=1;i<obstacleGrid.size();i++){
            if(obstacleGrid[i][0] == 0)
                dp[i][0] = dp[i-1][0];
            else 
                dp[i][0] = 0;
        }
        for(int j=1;j<obstacleGrid[0].size();j++){
            if(obstacleGrid[0][j] == 0)
                dp[0][j] = dp[0][j-1];
            else
                dp[0][j] = 0;
        }

        for(int i= 1; i<obstacleGrid.size();i++){
            for(int j = 1;j<obstacleGrid[0].size();j++){
                if(obstacleGrid[i][j] == 1)
                    dp[i][j]=0;
                else 
                    dp[i][j]=dp[i][j-1]+ dp[i-1][j];
            }
        }
    return  dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];

    }

};
```