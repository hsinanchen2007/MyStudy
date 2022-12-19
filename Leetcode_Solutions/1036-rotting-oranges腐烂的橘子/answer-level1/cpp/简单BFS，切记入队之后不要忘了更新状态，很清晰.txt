```
    int h[4]={-1,1,0,0};
    int l[4]={0,0,-1,1};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int> > que;
        int count=0; //记录新鲜橘子个数
        int res=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){//腐烂橘子入队，记录新鲜橘子数量
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count+=1;
                }else if(grid[i][j]==2){
                    que.push(make_pair(i,j));
                }
            }
        }
        if(count==0) return 0;//没有新鲜橘子，直接返回。
        while(!que.empty()){
            int N=que.size();
            for(int i=0;i<N;i++){
                pair<int,int> p=que.front();
                que.pop();
                for(int j=0;j<4;j++){//  上下左右
                    int x=p.first+h[j];
                    int y=p.second+l[j];
                    if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1){// 入队条件（在矩阵内，是新鲜橘子）
                        count--;
                        que.push(make_pair(x,y));
                        grid[x][y]=2;  //不要忘了更新状态
                    }
                }
            }
            res++;
        }
        if(count==0) return res-1;// 若最后新鲜橘子为0，返回结果，否则返回-1
        else return -1;
    }
```
