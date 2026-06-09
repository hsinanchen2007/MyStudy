### 解题思路
(1)
已知：一个n节点图的最小生成树必然包含n-1条边；
因此，当connection中包含的边数量小于n-1条时，无论怎么swap边，必然不可能构成原图的生成树， 直接return -1
(2)
对connection所提供的当前图模型，计算图中所有不相交集的个数，假设为M;
针对M个不相交集要形成生成树，每次两个子集在union过程中只需要引入一条边，而这条边的来源可以是原图中任意有圈环上的一条边（具体哪一条我们并不关心，任意的一条均可以，因为有圈图任意一条圈上的边被删除不会影响到图的联接性），而一次union对应使不相交集个数减一，因此M个不相交集最少需要M-1次union操作才能形成单一生成树（所有节点均在树上）。
(3)
上述的union操作所需要的边总能从connection原图中得到满足（只要满足条件1：边数量不小于n-1），因此最终答案即为M-1，即不相交集个数减1
### 代码

```cpp
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        //最小生成树问题/克鲁斯卡尔方法  计算不想交集个数
        if(connections.size()<n-1)    return -1;
        map<int, vector<int>> map;
        buildMap(n, connections, map);
        vector<bool> visited(n,false);
        int ans=0;
        queue<int> que;
        for(int i=0;i<n;i++)
        {
            if(map.find(i)==map.end())
            ans++;

        }
        
        while(!map.empty())
        {
            int start = map.begin()->first;
            que.push(start);
            while(!que.empty())
            {
               int curr = que.front();
                que.pop();
                visited[curr] = true;
                vector<int> curr_childs = map[curr];
                for(int i=0;i<curr_childs.size();i++)
                {
                    int next = curr_childs[i];
                    if(visited[next]) continue;
                    visited[next] =true;
                    que.push(next);
                }
                map.erase(curr);
            }
            ans++;
        
        }
        return ans-1；
         
    }
    void buildMap(int n, vector<vector<int>>& connections, map<int, vector<int>>& map)
    {
        for(int i=0;i<connections.size();i++)
        {
            vector<int> temp = connections[i];
            map[temp[0]].push_back(temp[1]);
            map[temp[1]].push_back(temp[0]);
        }
    }
};
```