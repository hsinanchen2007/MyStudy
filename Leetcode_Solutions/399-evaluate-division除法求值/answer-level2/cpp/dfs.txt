- 将a/b=2映射为 边 a->b 权值为2和边 b->a 权值为1/2 完成图构建后求queries中对应的路径同时乘边权，如果能找到路径则返回边权的乘积否则返回-1
```cpp
class Solution {
public:
    struct Node{
        string to;
        double cost;
    };
    bool flag=0;
    unordered_map<string,vector<Node>>G;
    unordered_map<string,bool>vis;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        vector<double>res;
        for(int i=0;i<n;++i){
            Node n1,n2;
            n1.to = equations[i][1],n1.cost=values[i];
            G[equations[i][0]].push_back(n1);
            n2.to = equations[i][0],n2.cost=1/values[i];
            G[equations[i][1]].push_back(n2);
        }
        for(auto c:queries){
            vis.clear();
            flag=0;
            double current = 1;
            vis[c[0]]=1;
            double temp = dfs(c[0],c[1],current);
            if(flag)res.push_back(temp);
            else res.push_back(-1);
            vis[c[0]]=0;
        }
        return res;
    }
    double dfs(string start,string end,double &current){
        if(G.find(start) == G.end()){
            flag=0;
            return -1;
        }
        if(start == end){
            flag=1;
            return current;
        }
        for(auto e:G[start]){
            if(vis[e.to])continue;
            current*=e.cost;
            vis[e.to]=1;
            dfs(e.to,end,current);
            if(flag)break;
            current/=e.cost;
            vis[e.to]=0;
        }
        return current;
    }
};
```