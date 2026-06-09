执行用时 :20 ms, 在所有 cpp 提交中击败了94.74%的用户
内存消耗 :11.1 MB, 在所有 cpp 提交中击败了88.73%的用户

广度优先染色：

    bool isBipartite(vector<vector<int>>& graph) {
        int N=graph.size();
        vector<int> color(N);
        queue<int> q;
        for(int i=0;i<N;i++){
            if(color[i]==0){
                q.push(i);
                color[i]=1;
                while(!q.empty()){
                    i=q.front();
                    q.pop();
                    for(auto& j:graph[i]){
                        if(color[j]==0){
                            q.push(j);
                            color[j]=-color[i];
                        }
                        else if(color[i]==color[j]){
                            return false;
                        }
                    }
                }
            }
            
        }
        return true;
    }

深度优先染色：

    bool dfs(vector<vector<int>>& graph,vector<int>& color,int i,int col){
        color[i]=col;
        for(auto j:graph[i]){
            if(color[j]==color[i]||(color[j]==0&&!dfs(graph,color,j,-col))){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int N=graph.size();
        vector<int> color(N);
        for(int i=0;i<N;i++){
            if(color[i]==0&&!dfs(graph,color,i,1)){
                return false;
            }
        }
        return true;
    }
    