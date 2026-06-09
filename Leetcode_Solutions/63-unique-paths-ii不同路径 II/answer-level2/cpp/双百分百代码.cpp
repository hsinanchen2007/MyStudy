![image.png](https://pic.leetcode-cn.com/0c47275b5406b2040ae8fbdae8471f04acf602a508ab7c56370f2a8df2ef83e9-image.png)
```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	//有测试用例是刚开始就是障碍。。。。狗的很
        if(obstacleGrid[0][0] == 1) return 0;
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        //因为这题用int会导致数据溢出，所以用long long来存
        vector<vector<long long>> v(rows, vector<long long>(cols, 0));
        for(int i = 0;i < obstacleGrid.size();i++){
            for(int j = 0;j < obstacleGrid[0].size();j++){
            	//可以走的几种情况分开处理
                if(obstacleGrid[i][j] == 0){
                    if(i == 0 && j == 0){
                        v[i][j] = 1;
                        continue;
                    }
                    if(i == 0){
                        v[i][j] = v[i][j-1];
                        continue;
                    }
                    if(j == 0){
                        v[i][j] = v[i-1][j];
                        continue;
                    }
                    if(i != 0 && j!= 0){
                        v[i][j] = v[i][j-1] + v[i-1][j];
                        continue;
                    }
                }
                //障碍就把它设为0，防止对后面产生贡献
                if(obstacleGrid[i][j] == 1){
                    v[i][j] = 0;
                }
            }
        }
        //输出结果
        return v[v.size()-1][v[0].size()-1];
    }
};
```

