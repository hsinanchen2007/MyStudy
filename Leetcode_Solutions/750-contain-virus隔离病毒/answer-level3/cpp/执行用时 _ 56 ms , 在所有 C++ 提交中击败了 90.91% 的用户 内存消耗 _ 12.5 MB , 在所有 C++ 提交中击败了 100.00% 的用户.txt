    class Solution {
    public:
        int n,m;
        struct point{
            int x,y;
        };
        int d[4][2]={1,0,-1,0,0,1,0,-1};
        stack<point> S;
        vector<vector<point>> quyu;
        void DFS(vector<vector<int>>& grid){
            vector<point> V;
            quyu.clear();
            vector<vector<int>>visit(n,vector<int>(m,0));
            for(int i=0;i<n;++i)//记录所有的感染点
                for(int j=0;j<m;++j){
                    if(grid[i][j]==1&&visit[i][j]==0){
                        V.clear();
                        point temp;
                        temp.x=i;
                        temp.y=j;
                        visit[i][j]=1;
                        S.push(temp);
                        while(!S.empty()){
                            temp=S.top();
                            V.push_back(temp);
                            S.pop();
                            int X=temp.x;
                            int Y=temp.y;
                            for(int k=0;k<4;++k){
                                temp.x=X+d[k][0];
                                temp.y=Y+d[k][1];
                                if(temp.x>=0&&temp.x<n&&temp.y>=0&&temp.y<m&&visit[temp.x][temp.y]==0&&grid[temp.x][temp.y]==1){
                                    S.push(temp);
                                    visit[temp.x][temp.y]=1;
                                }
                            }
                        }
                        quyu.push_back(V);
                    }
                }
            
        }
        int findMAX(vector<vector<int>>& grid){
            vector<vector<int>> G0=grid;
            int max=0;
            int max0=-1;
            int z=0;
            for(int i=0;i<quyu.size();++i){
                z=0;
                for(int j=0;j<quyu[i].size();++j){
                    point temp=quyu[i][j];
                    for(int k=0;k<4;++k){
                        int X=temp.x+d[k][0];
                        int Y=temp.y+d[k][1];
                        if(X>=0&&X<n&&Y>=0&&Y<m&&grid[X][Y]==0){
                            z++;
                            grid[X][Y]=1;
                        }
                    }
                }
                if(z>max){
                    max0=i;
                    max=z;
                }
                grid=G0;
            }
            if(max0>=0){
                max=0;
                for(int i=0;i<quyu[max0].size();++i){
                    point temp=quyu[max0][i];
                    for(int k=0;k<4;++k){
                        int X=temp.x+d[k][0];
                        int Y=temp.y+d[k][1];
                        if(X>=0&&X<n&&Y>=0&&Y<m&&grid[X][Y]==0){
                            max++;
                        }
                    }
                    grid[temp.x][temp.y]=2;
                }
                quyu.erase(quyu.begin()+max0);
            }
            for(int i=0;i<quyu.size();++i){
                for(int j=0;j<quyu[i].size();++j){
                    point temp=quyu[i][j];
                    for(int k=0;k<4;++k){
                        int X=temp.x+d[k][0];
                        int Y=temp.y+d[k][1];
                        if(X>=0&&X<n&&Y>=0&&Y<m&&grid[X][Y]==0){
                            grid[X][Y]=1;
                        }
                    }
                }
            }
            return max;
        }
        int containVirus(vector<vector<int>>& grid) {
            n=grid.size();
            m=grid[0].size();
            int s,end=0;
            DFS(grid);
            while(s=findMAX(grid)){
    DFS(grid);
            end+=s;
        }
            return end;
        }
    };