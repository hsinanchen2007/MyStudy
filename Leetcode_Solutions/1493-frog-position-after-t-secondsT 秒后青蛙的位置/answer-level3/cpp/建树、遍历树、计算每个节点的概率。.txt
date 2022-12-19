遍历一遍树，计算出①走到每个结点的概率 ②走到每个结点需要的步数(即深度、或者说层数) ③每个结点的孩子数。
遍历完后。
若target对应的层数恰好等于步数t，直接返回target对应的概率即可。
若target对应的层数大于步数t，且target对应的结点是叶子结点(即孩子数为0)，也直接返回target对应的概率即可。（因为青蛙跳不动时，会在原地跳）。
否则返回0.0 因为如果不是上面两种情况，青蛙注定跳不到。
如果target不是叶子结点，只要layer[target]不等于t，青蛙就跳不到。
如果target是叶子结点，但是layer[target]>t, 青蛙也跳不到。

```cpp
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        double gailv[101];
        int layer[101];
        childnum = new int[101]();
        ljb=vector<vector<int>>(n+1);
        for(int i=0; i<edges.size(); i++){
            ljb[edges[i][0]].push_back(edges[i][1]);
            ljb[edges[i][1]].push_back(edges[i][0]);
        }
        gailv[1]=1.0;
        layer[1]=0;
        looked=vector<bool>(n+1, false);
        dfs(1, gailv, layer);
        //return layer[target];
        if(layer[target]==t ||(layer[target]<t && childnum[target]==0) )
            return gailv[target];
        return 0.0;
    }
    void dfs(int start, double* gailv, int *layer){
        if(looked[start]) return;
        looked[start]=true;
        int c=0;
        for(int i=0; i<ljb[start].size(); i++){
            if(looked[ljb[start][i]]) continue;
            int t=start==1?ljb[start].size():(ljb[start].size()-1);
            gailv[ljb[start][i]]=gailv[start]*(1.0/t);
            layer[ljb[start][i]]=layer[start]+1;
            c++;
        }
        childnum[start]=c;
        for(int i=0; i<ljb[start].size(); i++){
            dfs(ljb[start][i], gailv, layer);
        }
    }
    vector<vector<int>> ljb;
    vector<bool> looked;
    int *childnum;
};
```
