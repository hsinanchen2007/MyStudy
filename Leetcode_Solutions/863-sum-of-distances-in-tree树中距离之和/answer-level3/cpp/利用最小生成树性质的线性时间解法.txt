1. 如果采用暴力BFS，需要n次BFS，那么时间复杂度为o(n^2)。
2. 相连接的节点i和j,如果断开i和j的连接，树会被一分为二。假设i这边树节点有Vertices[i]个，j这边树节点有Vertices[j]个，可以推出如下关系式：ans[i] + Vertices[i] = ans[j] + Vertices[j].
3. 最小生成树可以从任何节点出发构建一颗树，简便起见从0出发建树,并计算Vertices。
4. 利用第2点和第3点，我们可以先一次BFS求得ans[0],然后遍历树，根据父节点的ans求得子节点的ans。
5. 时间复杂度为o(n),空间复杂度o(n^2).
```
class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        //构造邻接矩阵nearby
        vector<vector<int>> nearby(N);
        for(auto edge:edges)
        {
            nearby[edge[0]].push_back(edge[1]);
            nearby[edge[1]].push_back(edge[0]);
        }
        //构造树，父节点i的子节点存在kid[i]中
        vector<vector<int>> kid(N);
        vector<bool> visited(N,false);
        visited[0] = true;
        stack<int> s;
        s.push(0);//将0作为父节点
        stack<int> new_s;
        int count = 1;
        while(count < N)
        {
            while(!s.empty())
            {
                int p = s.top();
                s.pop();
                for(auto i:nearby[p])
                {
                    if(!visited[i])
                    {
                        kid[p].push_back(i);
                        visited[i] = true;
                        new_s.push(i);
                        count++;
                    }
                }
            }
            swap(s,new_s);
        }
        //递归计算每个节点i的子节点数量V[i]
        vector<int> V(N);
        countV(0,V,kid);
        //计算ans[0]
        vector<int> ans(N);
        ans[0] = bfs(0,0,kid);
        //线性时间计算ans
        countAns(0,N,ans,V,kid);
        return ans;
    }
    void countV(int node,vector<int>& V,vector<vector<int>> &kid)
    {
        if(kid[node].empty())
        {
            V[node] = 0;
        }
        else
        {
            int c = 0;
            for(auto i:kid[node])
            {
                countV(i,V,kid);
                c += V[i] + 1;
            }
            V[node] = c;
        }
    }
    int bfs(int node,int cost,vector<vector<int>> &kid)
    {
        int total_cost = cost;
        if(kid[node].empty())
        {
            return total_cost;
        }
        else
        {
            for(auto i:kid[node])
            {
                total_cost += bfs(i,cost+1,kid);
            }
            return total_cost;
        } 
    }
    void countAns(int node,int N,vector<int> &ans,vector<int>& V,vector<vector<int>> &kid)
    {
        if(V[node] == 0)
            return;
        else
        {
            for(auto i:kid[node])
            {
                ans[i] = ans[node] - (1 + V[i]) + (N - V[i] - 1);
                countAns(i,N,ans,V,kid);
            }    
        }
        return;
    }
};
```
