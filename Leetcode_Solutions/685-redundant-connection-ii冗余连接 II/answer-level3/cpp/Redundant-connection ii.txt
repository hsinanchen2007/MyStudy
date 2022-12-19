### 解题思路
讨论两种情况：
1.多余的边连接上的是根节点，那么就会产生一个环,且每个节点的入度数为1，返回最后构成环的边；
2.多余的边连接上的是非跟节点，那么就会有一个节点入度为2,记为q1,
  记录这个节点的两个父亲节点p1,p2;
  如果（p1,q1)在环中，返回（p1,q1)；否则返回（p2,q2);

### 代码

```cpp
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> result1,result;
        map<int,vector<int>> verlist,parent;
        map<int,bool> visited;
        int wnode=0;
        for(auto &edge:edges){
            for(auto &p:visited) p.second = false;
            visited[edge[0]]=false;
            visited[edge[1]]=false;
            if(parent.find(edge[1])==parent.end()){
                vector<int> *tmp=new vector<int>;
                (*tmp).push_back(edge[0]);
                parent[edge[1]]=(*tmp);
            }else { parent[edge[1]].push_back(edge[0]); wnode=edge[1]; }
            if(wnode==0&&dfs(verlist,visited,edge[1],edge[0])) result1=edge;
            if(verlist.find(edge[0])==verlist.end()){
                vector<int> *tmp=new vector<int>;
                (*tmp).push_back(edge[1]);
                verlist[edge[0]]=(*tmp);
            }else verlist[edge[0]].push_back(edge[1]);
        }
        if(wnode==0) return result1;
        if(dfs(verlist,visited,wnode,parent[wnode][0]))  
            result.push_back(parent[wnode][0]);
        else result.push_back(parent[wnode][1]);
        result.push_back(wnode);
        return result;
        
    }
    bool dfs(map<int,vector<int>> &verlist,map<int,bool> &visited,int a,int b){
        visited[a]=true;
        if(a==b) return true;
        if(verlist.find(a)==verlist.end()) return false;
        for(auto p:verlist[a]){
            if(visited[p]==false&& dfs(verlist,visited,p,b)) return true;
        }
        visited[a]=false;
        return false;
    }
    
};
```