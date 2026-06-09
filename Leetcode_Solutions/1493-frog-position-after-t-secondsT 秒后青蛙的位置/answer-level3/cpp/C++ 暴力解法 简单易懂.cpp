# 解题思路

先求出每一个点的出度n， 从上一层选到这一层的概率就是1/n。
再找到一条唯一的路径，可以用DFS， 也可以直接暴力解， 把路径添加到一个数组中，求出所有点的出度之和，即可算出总概率。

要注意的是那个时间t， 如果t小于路径上的结点总和，那肯定不能走到，如果大于，那么要分两种情况讨论，一种是目标点后面是否还有结点，有的话就根据规则必须前进（有剩余时间的情况下），所以不成功。另一种就可以继续计算概率

# 代码
```c++
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int, int> hashmap;
        vector<int> road;
        
        for (int i = 0; i < edges.size(); i++) 
        {
            if (edges[i][0] > edges[i][1])              //调整
                swap(edges[i][1], edges[i][0]);

            if (hashmap.count(edges[i][0]) > 0) {       //求出度
                hashmap[edges[i][0]]++;
                continue;
            }
            hashmap[edges[i][0]] = 1;
        }

        int x = target;
        while(x != 1)        //寻找路径
        {    
            for(int i = 0; i < edges.size(); i++){
                if(edges[i][1] == x){
                    road.push_back(edges[i][0]);
                    x = edges[i][0];
                    break;
                }
            }
        }

        if (t > road.size()) {
            if (hashmap[target] != 0)
                return 0;
        }
        else if(t < road.size())
            return 0;
        
        double probability = 1;       
        for(int i = 0; i < road.size(); i++)
            probability *= 1 / (double)hashmap[road[i]];
        
        return probability;      
    }
};
```
