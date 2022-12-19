拓扑排序：
1. 将所有入度为0的点入队列。
2. 出队列的点U，与其相连的点的入度减去1，同时如果存在新的入度为0的点入队列，通过一定方法标识该店被访问（本人是将入度置为-1）
3. 若队列不为空重复2.若为空，检查所有点是否访问完毕（本人检查所有入度是否为-1）。
```

     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>degree(numCourses,0);//声明入度
        vector<forward_list<int>>G(numCourses,forward_list<int>({}));//声明图（邻接链表）
        for(auto p:prerequisites){
            ++degree[p[0]];//读入入读
            G[p[1]].push_front(p[0]);//读入图
        }
        queue<int>que;//存放入度为0的点
        for(int i = 0;i<numCourses;++i){
            if(degree[i]==0)
                que.push(i);
        }
        
        while(que.size()>0){
            int u = que.front();
            que.pop();
            degree[u] = -1;
            for(auto v:G[u]){
                --degree[v];
                if(degree[v]==0)
                    que.push(v);
            }
            
        }
        
        for(int i = 0;i<numCourses;++i){
            if(degree[i]!=-1)
                return false;
        }
        
        return true;
    }
```


DFS实现拓扑排序
白色代表没被访问，灰色代表该节点被访问但子节点还没被访问完成，黑色代表子节点也被访问



```
class Solution {
public:
    typedef vector<forward_list<int>> Graph;//（邻接链表代表图）
    enum color{white,gray,black};
    
    bool DFS(const Graph & G,vector<color>& visit,int i){
         visit[i] = gray;
        for(auto & p:G[i]){
            if(visit[p]==white){
               if(!DFS(G,visit,p))
                   return false;
            }
            else if(visit[p]==gray)
                return false;
        }
        visit[i] = black;
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph  G(numCourses,forward_list<int>({}));//声明图
        for(auto p:prerequisites){
            G[p[1]].push_front(p[0]);//读入图
        }
        vector<color>isVisit(numCourses,white);
        for(int i = 0; i <numCourses;++i ){
            if(!DFS(G,isVisit,i)){
                return false;
            }
        }
        return true;
    }
};
```
