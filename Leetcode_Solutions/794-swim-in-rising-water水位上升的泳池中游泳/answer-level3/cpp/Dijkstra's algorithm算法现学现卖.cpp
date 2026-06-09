![360截图20190922165653809.jpg](https://pic.leetcode-cn.com/810faa7be49647b2d84507f3d9d1b93c897f46bdda5cdc011689ab9a8b7a1df9-360%E6%88%AA%E5%9B%BE20190922165653809.jpg)
`一开始不清楚 这类题可以用Dijkstra's algorithm做，于是看了一眼题目就准备动态规划。
`
其实动态规划做这个问题的主要麻烦在于：
动态规划的问题必须是可以划分为子问题的，并且不在乎子问题的来由，可是这个问题的关键在于，随着动态规划中状态的转移，存在某些点被遗漏了，也就是说动态规划一直在找某个f[i,j],的最优时间，但是忽略了这道题中水流的特点，就是可能某个f[i,j]求解结束后，求到某个f[p,q]时，f[i,j]需要被刷新，这个在动态规划中是没办法处理的。


于是，看了一眼题解界面看到一个字眼Dijkstra's algorithm，于是上网搜索了一下该算法，学习了一下，总结为一句话：贪心+回溯

贪心是：在回溯的表中贪心
回溯是：在记录每次贪心周围的情况并排序

至少我的理解就是以上两个特点，其实这里用贪心 可能有点不完全恰当，因为按道理贪心会去搜索当前最优才对，这就意味着应该不断向着[N,N]点前进，
但是这里的贪心的目的是**，将所有回溯表哥中记录的平台水位最低的平台周围的水位情况刷新**，然后再加入到回溯表格中。
下面是代码：
```C++ []
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        if (grid.size() == 1) {
            return grid[0][0];
        }
        vector<vector<int>> res(grid.size(),vector<int>(grid.size(),INT_MAX));
        multimap<int,pair<int,int>> lut;
        // init
        res[0][0] = grid[0][0];
        int i = 0;
        int j = 0;
        int lasti = INT_MAX;
        int lastj = INT_MAX;
        int N = (grid.size() - 1);
        lut.insert(pair<int,pair<int,int>>(res[i][j],pair<int,int>(i,j)));

        while (true) {
            if (lut.size() == 0) {
                if (i == N && j ==N) {
                    break;
                }
                break;
            }
            i = lut.begin()->second.first;
            j = lut.begin()->second.second;
            lut.erase(lut.begin());        
            // cout << i << " " << j << " " << lasti << " " << lastj << " ";  
            int tmp;
            if (i != N) {
                tmp = res[i + 1][j];
                CalcRes(res[i][j], res[i + 1][j], grid[i][j], grid[i + 1][j]);
                if (tmp != res[i + 1][j]) {
                    lut.insert(pair<int,pair<int,int>>(res[i + 1][j],pair<int,int>(i + 1,j)));

                }   
            }
            if (j != N) {
                tmp = res[i][j + 1];
                CalcRes(res[i][j], res[i][j + 1], grid[i][j], grid[i][j + 1]);
                if (tmp != res[i][j + 1]) {
                    lut.insert(pair<int,pair<int,int>>(res[i][j + 1],pair<int,int>(i,j + 1)));                  
                }                
                
            }
            if (i != 0) {
                tmp = res[i - 1][j];
                CalcRes(res[i][j], res[i - 1][j], grid[i][j], grid[i - 1][j]);
                if (tmp != res[i - 1][j]) {
                    lut.insert(pair<int,pair<int,int>>(res[i - 1][j],pair<int,int>(i - 1,j)));                  
                }                
                
            }            
            if (j != 0) {
                tmp = res[i][j - 1];
                CalcRes(res[i][j], res[i][j - 1], grid[i][j], grid[i][j - 1]);
                if (tmp != res[i][j - 1]) {
                    lut.insert(pair<int,pair<int,int>>(res[i][j - 1],pair<int,int>(i,j - 1)));                   
                }                
                
            }
            lasti = i;
            lastj = j;   
        } 
        return res[grid.size() - 1][grid.size() - 1];
    }

    void CalcRes(int &resNow, int &resFro, int &highNow, int &highFro) 
    {
        if (highNow < highFro && resNow < highFro) {
            resFro = highFro;
        } else {
            resFro = min(resFro, resNow);
        }
    }
    
};
```

