    class Solution {
        public:
            vector<int> vx,vy;
            int juli(vector<vector<int>>& grid,int x,int y){
                int end=0;
                for(int i=0;i<vx.size();++i){
                    end+=abs(vx[i]-x)+abs(vy[i]-y);
                }
                return end;
            }
            int minTotalDistance(vector<vector<int>>& grid) {
                int min;
                for(int i=0;i<grid.size();++i)
                    for(int j=0;j<grid[0].size();++j){
                        if(grid[i][j]==1){
                            vx.push_back(i);
                            vy.push_back(j);
                        }
                    }
                int X=0,Y=0;
                sort(vy.begin(),vy.end());
                X=vx[vx.size()/2];
                Y=vy[vy.size()/2];
                return juli(grid,X,Y);
            }
    };
