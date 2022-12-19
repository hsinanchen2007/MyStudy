1. 首先是建图：richer[x,y],x比y富有那就连一条从y到x的有向边 y——>x,我用的是邻接表，链式前向星也可以试一下
    vector<int> edge[505];
    for(int i=0;i<richer.size();i++){
        edge[richer[i][1]].push_back(richer[i][0]);
    }
2. dfs+记忆化:
    int d[505];
    int dfs(int u,vector<int>& quiet){
        if(d[u]) return d[u];//有值就返回不必重复搜
        int mi=quiet[u],res=u;//mi存最小值，res存返回的节点(就是人的编号)
        for(int i=0;i<edge[u].size();i++){
            if(mi>quiet[dfs(edge[u][i],quiet)]){//dfs返回的是编号，那quiet[dfs(edge[u][i],quiet)]不就是安静值嘛
                mi=quiet[dfs(edge[u][i],quiet)];//比较更新最小安静值
                res=dfs(edge[u][i],quiet);//比较更新节点
            }
        }
        d[u]=res;//存储
        return res;//返回答案
    }
3. 主函数代码：
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet){
        memset(d,0,sizeof(d));//初始化以防玄学
        vector<int> ans;
        for(int i=0;i<=quiet.size();i++){//初始化
            edge[i].clear();
        }
        if(richer.size()==0){//当没有贫富关系的时候，就勇敢做自己，answer[i]=i;
            for(int i=0;i<quiet.size();i++){
                ans.push_back(i);
            }
            return ans;
        }
        for(int i=0;i<richer.size();i++){//建图
            edge[richer[i][1]].push_back(richer[i][0]);
        }
        for(int i=0;i<quiet.size();i++){//dfs
            ans.push_back(dfs(i,quiet));
        }
        return ans;
    }

