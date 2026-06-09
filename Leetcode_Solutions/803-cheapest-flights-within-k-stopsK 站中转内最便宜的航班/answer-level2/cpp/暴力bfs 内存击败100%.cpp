```
class Solution {
public:
    struct Node{
        int num;
        int k;
        int money;
    };
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        Node s;
        s.num=src;
        s.k=-1;
        s.money=0;
        queue<Node> q;
        q.push(s);
        vector<int> mon;
        int vis[100];//访问标志
        memset(vis,0x3f3f3f3f,sizeof(vis));
        vis[src]=0;
        while(!q.empty()){
            Node n=q.front();
            q.pop();
            if(n.k<=K){
                if(n.num==dst){//到达终点
                    mon.push_back(n.money);
                }else{
                    for(int i=0;i<flights.size();i++){
                        if(flights[i][0]==n.num&&vis[flights[i][1]]>=n.money+flights[i][2]){
                            Node newn;
                            newn.num=flights[i][1];
                            newn.k=n.k+1;
                            newn.money=n.money+flights[i][2];
                            vis[flights[i][1]]=n.money+flights[i][2];
                            q.push(newn);
                        }
                    }
                }
                
            }
        }
        if(mon.size()==0)return -1;
        int min=0x3f3f3f3f;
        for(int i=0;i<mon.size();i++){
            if(mon[i]<min){
                min=mon[i];
            }
        }
    
        return min;
    }
};
```
