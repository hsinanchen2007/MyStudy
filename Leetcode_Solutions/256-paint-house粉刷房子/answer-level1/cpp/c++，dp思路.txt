# 思路
看到这道题，给我的感觉就是需要使用dp，因此简单来分析下我的思路。
dp最常见的思路就是假设知道第n-1个状态，然后考虑第n个状态。看是否可行。
1. 错误：虽然这是错误思路，但有一定借鉴性。我考虑我知道第n-1的最小cost值，那么我当前的最小mincost[n] = min(costs[n][0], costs[n][1], costs[n][2]) + mincosts[n-1]，很容易就知道这是个错误的思路。
2. 分析下我们上面的思路为什么错？
    2.1 对于前状态，我们要知道上一次粉刷的是color，我们才能确定，我们当前状态才知道选择哪个color
    2.2 但这还不够，实际上我们要知道上一个状态的三种color的各自的cost，才能确定当前用哪个color的cost最小。换过来思考。当前我们就刷0这种颜色，minCost[n][0] = costs[n][0] + min(minCost[n-1][1], minCost[n-1][2])。

例子，假设[10, 11, 17], [1, 10, 17]
这种情况，如果我们仅仅是先选前面cost最低的，然后再选当前cost，选出来是10 + 10 = 20。
是没有11 + 1 = 12好的。也就是说我们在上一次选择时候需要吃亏。所以我们要知道更多的信息。即上次选择颜色0的总cost，选择1的总cost。。。代码中，我们就可以用一个数组来表示。每次都要更新。很容易我们就写出了注释处的代码，但一般这样的代码stack展开的深度过长，所以我们再将其修改成递推式即可。
## 代码
```cpp
class Solution {
public:
    // 典型的动态规划问题
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty())
            return 0;
        vector<int> threeCosts = costs[0];
        for(int i = 1; i < costs.size(); i++){
            vector<int> res(3, 0);
            res[0] = costs[i][0] + min(threeCosts[1], threeCosts[2]);
            res[1] = costs[i][1] + min(threeCosts[0], threeCosts[2]);
            res[2] = costs[i][2] + min(threeCosts[0], threeCosts[1]);
            threeCosts = res;
        } 
        return getMin(threeCosts);
    }
    /*
    int minCost(vector<vector<int>>& costs) {
        vector<int> res;
        res = minCost(costs, costs.size() - 1);
        return getMin(res);
    }
    vector<int> minCost(vector<vector<int>>&costs, int n){
        vector<int> threeCosts(3, 0);
        if(n == 0){
            threeCosts[0] = costs[0][0];
            threeCosts[1] = costs[0][1];
            threeCosts[2] = costs[0][2];
            return threeCosts;
        }
        threeCosts = minCost(costs, n-1);
        vector<int> res(3, 0);
        // 更新第1个位置
        res[0] = costs[n][0] + min(threeCosts[1], threeCosts[2]);
        res[1] = costs[n][1] + min(threeCosts[0], threeCosts[2]);
        res[2] = costs[n][2] + min(threeCosts[0], threeCosts[1]);
        return res;
    }
    
    */
    int getMin(const vector<int>& ivec){
        int res = ivec[0];
        for(size_t i = 1; i <ivec.size(); i++){
            if(ivec[i] < res) 
                res = ivec[i];
        }
        return res;
    }
};
```