class Solution {
public:
    int flag[10100];//flag==1表示该节点是最终安全的，flag==2表示该节点处在一个可以到达环的路径，
                    //flag==0表示该节点还被没有判断
    bool vis[10100];
    vector<int> res;
    vector<int> node;
    bool dfs(int now,vector<vector<int> >& graph){
        node.push_back(now);
        for(int i=0;i<graph[now].size();i++){
            if(flag[graph[now][i]]==1) continue;//如果该子节点是安全的那么，不用重复判断
            if(vis[graph[now][i]]==false&&flag[graph[now][i]]==0){//该子节点没有到达且没有判断
                vis[graph[now][i]]=true;
                bool b=dfs(graph[now][i],graph);
                vis[graph[now][i]]=false;
                if(!b) {//子节点返回false，那么now也是不安全的
                    flag[now]=2;
                    node.pop_back();
                    return b;
                }
            }else {//该子节点已经到达过，或该子节点已经被判断为不安全
                flag[now]=2;
                node.pop_back();
                return false;
            }
        }
        flag[now]=1;//安全退出，表示该节点是安全的
        node.pop_back();
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        memset(flag,0,sizeof(flag));
        int size=graph.size();
        for(int i=0;i<size;i++){
            if(flag[i]==2) continue;
            vis[i]=true;
            bool b=dfs(i,graph);
            vis[i]=false;
            if(b) res.push_back(i);//如果返回true表示该节点是安全的
        }
        return res;
    }
};