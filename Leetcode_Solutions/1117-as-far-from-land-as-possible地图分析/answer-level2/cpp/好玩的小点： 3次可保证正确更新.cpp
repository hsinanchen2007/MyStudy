### 解题思路
思路是这样的： 对海洋区域，看周围（上下左右）的海洋到陆地的最短距离，+1就是自己到最近陆地的距离
具体是这样的： 
     初始化： 海洋区域 = INT_MAX; 陆地 = 0
     遍历地图：if 海洋, then dis = 周围的区域到最近距离中最小的一个 +1
              那么， 对于周围是海洋的 海洋 ==》不更新距离

     最后，每个区域的dis 最大的就是answer了

！ 好玩的地方在于：  更新多少次才能保证每个dis是正确的
不正确的因素：
     1. 如刚刚所讲，周围是海洋的海洋不更新（更新也是无意义的）
     2. 区域更新是有先后的：也就是说，新的更新的海洋和在它前面的距离是对的，而后面陆地根本就没有影响到它
     3. 但是现实是： 距离前面的陆地和后面的陆地是等价的
比如：
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 1 
这样的地图 从【0，0】开始遍历 得 长边+1 次 才能保证所有海洋更新正确
     当然，从【n-1,n-1】开始遍历，换个地图也会有同样的问题

！想说的来了。。： 更新3次就可以保证了
那就是 从【0，0】一次，【n-1，n-1】一次，【0，0】一次就可以了

很多情况下，都是类似的

### 代码

```cpp
class Solution {
public:

    int findIt(vector<vector<int>>& dis, vector<vector<int>>& grid){
        int numZero = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 0){         // 对于海洋 查看周围的区域的距离
                    int min = INT_MAX;
                    if (j+1<m )
                        min = dis[i][j+1] < min ? dis[i][j+1] : min;
                    if (i+1<n )
                        min = dis[i+1][j] < min ? dis[i+1][j] : min;
                    if (j-1>= 0 )
                        min = dis[i][j-1] < min ? dis[i][j-1] : min;
                    if (i-1>= 0 )
                        min = dis[i-1][j] < min ? dis[i-1][j] : min;
                    
                    if (min != INT_MAX){ // 有改变才需要更改
                                   
                        dis[i][j] = min+1;
                    }    
                    else{
                        numZero ++; // 还有没有标记的0的数量
                    }
                }
            }
        }
        return numZero;
    }
    int findItRed(vector<vector<int>>& dis, vector<vector<int>>& grid){
        int numZero = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=n-1; i>=0; i--){
            for (int j=m-1; j>=0; j--){
                if (grid[i][j] == 0){         // 对于海洋 查看周围的区域的距离
                    int min = INT_MAX;
                    if (j+1<m )
                        min = dis[i][j+1] < min ? dis[i][j+1] : min;
                    if (i+1<n )
                        min = dis[i+1][j] < min ? dis[i+1][j] : min;
                    if (j-1>= 0 )
                        min = dis[i][j-1] < min ? dis[i][j-1] : min;
                    if (i-1>= 0 )
                        min = dis[i-1][j] < min ? dis[i-1][j] : min;
                    
                    if (min != INT_MAX){ // 有改变才需要更改
                                   
                        dis[i][j] = min+1;
                    }    
                    else{
                        numZero ++; // 还有没有标记的0的数量
                    }
                }
            }
        }
        return numZero;
    }

    int maxDistance(vector<vector<int>>& grid) {
        vector<vector<int>>dis(grid.size(), vector<int>(grid[0].size())) ;

        int n = grid.size(), m = grid[0].size(); // 0
        for(int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 1)
                    dis[i][j] = 0;              // 已知距离陆地的距离
                else
                    dis[i][j] = INT_MAX;
            }
        }

     
        int num = findIt(dis, grid);
        int a = grid.size()>grid[0].size() ? grid.size() : grid[0].size();

        if (num == n*m)                 // all is 0
            return -1;
        
        //for (int i=0; i<a; i++)
            findItRed(dis, grid);
            findIt(dis, grid);

        int max = INT_MIN;
        for(int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (dis[i][j] > max)
                    max = dis[i][j];
            }
        }

        if (max == INT_MIN || max == INT_MAX || max == 0)
            return -1;              // all is 1
        else
            return max;

    }
};
```