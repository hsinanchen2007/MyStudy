用二维数组，这里用long long，用int会越界
```
lass Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(!obstacleGrid.size() || !obstacleGrid[0].size()) return 0;
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<vector<long long>> v(rows, vector<long long>(cols, 0));
        if(obstacleGrid[0][0] == 1) return 0;
        v[0][0] = 1;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(obstacleGrid[i][j] == 1) continue;
                if(!i && !j) continue;
                if(!i)
                    v[i][j] = v[i][j - 1];
                else if(!j)
                    v[i][j] = v[i - 1][j];
                else
                    v[i][j] = v[i][j - 1] + v[i - 1][j];
            }
        }
        return v[rows - 1][cols - 1];
    }
};
```

用一维数组
```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(!obstacleGrid.size() || !obstacleGrid[0].size()) return 0;
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<long long> v(cols, 0);
        if(obstacleGrid[0][0] == 1) return 0;
        v[0] = 1;


        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    v[j] = 0;
                    continue;
                }
                if(!i && !j) continue;


                if(!i)
                    v[j] = v[j - 1];
                else if(!j)
                    v[j] = v[j];
                else
                    v[j] += v[j - 1];
            }
        }
        return v[cols - 1];
    }
};
```
还写了一些别的leetcode的题解，分享一下看看有没有需要的，题解还会更新：[https://www.yuque.com/books/share/300e07be-6fc9-417d-bb05-c50f5dea1618?#](https://www.yuque.com/books/share/300e07be-6fc9-417d-bb05-c50f5dea1618?#)
顺带给自己推一波公众号，要是有兴趣可以关注：**麦芽糖的笔记本**
![image.png](https://pic.leetcode-cn.com/95c54eba219d34f176350f6968ff8d934a93879a43a12f926b2e05148b5833ca-image.png)

公众号回复**LC**，可以下载题解的pdf版本，pdf也会更新

![image.png](https://pic.leetcode-cn.com/a533ef6e9a37396c93e0d965e5ef389996a90e8c5b6a05d35aa19d918dcf8b86-image.png)


