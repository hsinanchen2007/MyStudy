typedef pair<int, int> P;
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<int>> edge(n);
        for(int i=0; i<graph.size(); i++){
            edge[graph[i][0]].push_back(graph[i][1]);
        }
        priority_queue<P, vector<P>, greater<P> > myque;
        int dist[n];
        for(int i=0; i<n; i++){
            dist[i] = 1e9;
        }
        dist[start] = 0;
        myque.push(P(0, start));
        while(!myque.empty()){
            P p = myque.top();
            myque.pop();
            int u = p.second;
            if(p.first > dist[u]){
                continue;
            }
            if(dist[u] != 1e9)
            for(int j=0; j<edge[u].size(); j++){
                if(dist[u] + 1 < dist[edge[u][j]]){
                    dist[edge[u][j]] = dist[u] + 1;
                    myque.push(P(dist[u] + 1, edge[u][j]));
                }   
            }
        }
        return dist[target] != 1e9;
    }
};