执行用时 :20 ms, 在所有 cpp 提交中击败了87.23%的用户
内存消耗 :12 MB, 在所有 cpp 提交中击败了100.00%的用户

    vector<int> F;
    //father(int i)表示找到并返回顶点i的父亲顶点
    int father(int i){
        if(i!=F[i]){
            F[i]=father(F[i]);
        }
        return F[i];
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        F.resize(n);
        int result=0;
        for(int i=0;i<n;i++){
            F[i]=i;
        }
        for(auto& e:edges){
            int f1=father(e[0]),f2=father(e[1]);
            if(f1>f2){
                F[f1]=f2;
            }
            else if(f1<f2){
                F[f2]=f1;
            }
        }
        for(int i=0;i<n;i++){
            if(i==F[i]){
                result++;
            }
        }
        return result;
    }

相比而言，dfs的运行时间惨不忍睹

    void dfs(vector<vector<int>>& graph,vector<bool>& visit,int i){
        for(int j=0;j<visit.size();j++){
            if(visit[j]==false&&graph[i][j]==1){
                visit[j]=true;
                dfs(graph,visit,j);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n,vector<int>(n));
        vector<bool> visit(n,false);
        int result=0;
        for(auto& e:edges){
            graph[e[0]][e[1]]=graph[e[1]][e[0]]=1;
        }
        for(int i=0;i<n;i++){
            if(visit[i]==false){
                visit[i]=true;
                dfs(graph,visit,i);
                result++;
            }
        }
        return result;
    }