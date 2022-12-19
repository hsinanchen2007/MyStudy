先把边改成邻接描述方便计算。
建立prob矩阵表示某时刻某点的概率，在函数间按引用传递。
用数组visited记录访问过的节点，如果邻接有没访问过的节点，把概率等分过去。

```
class Solution {
public:
    void visit(vector<vector<int>>&nb,vector<vector<double>>&prob,vector<int>visited,int place,double p,int t,int time){
        if(time>t||p<1e-6)return;
        prob[time][place]+=p;
        int nbn=0;
        for(int c:nb[place]){
            if(visited[c]==0)nbn++;
        }
        if(nbn==0){
            for(int tv=time+1;tv<=t;tv++){
                prob[tv][place]+=p;
            }
        }else{
            for(int c:nb[place]){
                if(visited[c]==0){
                    vector<int>visitedt=visited;
                    visitedt[place]=1;
                    visit(nb,prob,visitedt,c,p/nbn,t,time+1);
                }
            }
        }
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>>nb(n,vector<int>{});
        for(auto &e:edges){
            nb[e[0]-1].push_back(e[1]-1);
            nb[e[1]-1].push_back(e[0]-1);
        }
        vector<vector<double>>prob(t+1,vector<double>(n,0));
        vector<int>visited(n,0);
        visited[0]=1;
        visit(nb,prob,visited,0,1,t,0);
        return prob[t][target-1];
    }
};
```
