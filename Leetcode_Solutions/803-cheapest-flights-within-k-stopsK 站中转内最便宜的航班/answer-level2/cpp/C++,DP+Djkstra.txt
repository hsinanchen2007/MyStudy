# DP
```
class Solution {
public:
//最短路径dp求解：
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int dp[n+1][n+1];//dp[i][src]表示的是从src出发经过i个中间结点的最短路径
        memset(dp,0x3f,sizeof(dp));
        for(int i=0;i<=n;i++){
            dp[i][src]=0;
        }
        for(int i=1;i<=K+1;i++){//因为下面有dp[i-1],所以需要从i=1开始遍历。
            for(auto v:flights){
                dp[i][v[1]]=min(dp[i][v[1]],dp[i-1][v[0]]+v[2]);
            }
        }
        return dp[K+1][dst]==0x3f3f3f3f?-1:dp[K+1][dst];
    }
};
```
# Djkstra
### 这里一定要与djkstra算法进行区分，是一种改进的Djkstra算法，因为djkstra算法是在更新到某个结点之后，他的最短路径就确定了，就直接加入到数组中，下一次不会遍历这个结点了。
### 但是，这一题不能做这一步处理，因为可能不是最短的也有可能满足条件的->因为还要满足中间节点小于等于K，所以不需要去重操作，我写的是进化版本的Djksta算法，还是使用优先队列进行求解的！
```
class Node{
public:
    Node(int _cost,int _name,int _dist):pay(_cost),name(_name),dist(_dist){}

    int pay;
    int name;
    int dist;
};
struct cmp{
//下面的含义是重载小于号的含义
    bool operator() (Node& a,Node& b){
        return a.pay>b.pay;
    }
    
};
struct edge{
    int to;
    int cost;
};
class Solution {
public:
//Djkstra算法，使用优先队列求解，首先写出Dijkstra算法的模板
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        priority_queue<Node,vector<Node>,cmp>pq;//第一个参数是代价，第二个参数是到达结点位置。
        vector<edge>g[n+1];
        for(auto v:flights){
            edge e;
            e.to=v[1];
            e.cost=v[2];
            g[v[0]].push_back(e);
        }
        set<int>vis;
        vis.clear();
        pq.push({0,src,-1});
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            cout<<x.name<<" "<<vis.count(x.name)<<endl;
            //if(vis.count(x.name))continue;
            if(x.name==dst)return x.pay;
            //vis.insert(x.name);
            int n=g[x.name].size();
            for(int i=0;i<n;i++){
                edge v=g[x.name][i];
                if(x.dist<K){
                    pq.push({x.pay+v.cost,v.to,x.dist+1});
                }
                
            }
        }
        return -1;
    }
};
```