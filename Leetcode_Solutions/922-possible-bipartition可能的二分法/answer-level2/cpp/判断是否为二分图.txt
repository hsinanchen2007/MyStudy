```
class Solution {
private:
    vector<int> color;
    vector<vector<int>> edges;

    bool bitpart(int u,int c) {
        color[u] = c;
        for(int v : edges[u]) {
            if(color[v] != -1 && color[v] == c) {
                return false;
            }
            if(color[v] == -1 && !bitpart(v,!c))return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        edges.resize(N+1);
        for(vector<int> edg:dislikes) {
            edges[edg[0]].push_back(edg[1]);
            edges[edg[1]].push_back(edg[0]);
        }
        color.resize(N+1,-1);
        for(int i = 1;i <= N; ++i) {
            if(color[i] == -1 && !bitpart(i,0))return false;
        }
        return true;
    }
};
```
