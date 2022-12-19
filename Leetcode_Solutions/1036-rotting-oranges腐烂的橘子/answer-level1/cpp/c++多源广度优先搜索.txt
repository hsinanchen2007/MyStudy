```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        std::ios::sync_with_stdio(false);
        if(grid.empty()) return 0;
        queue<pair<int,int>> fu;
        int hao=0;
        int num_row=grid.size();
        int num_col=grid[0].size();
        for(int i=0;i<num_row;++i){
            for(int j=0;j<num_col;++j){
                if(grid[i][j]==1) ++hao;
                if(grid[i][j]==2) fu.push({i,j});
            }
        }
        int mins=0;
        while(!fu.empty()&&hao>0){
            ++mins;
            int count=fu.size();
            //std::cout<<count<<" min: "<<mins;
            while(count>0&&hao>0)
            {
                auto t=fu.front();
                fu.pop();
                if(t.first+1<num_row&&grid[t.first+1][t.second]==1){
                    --hao;
                    //std::cout<<"[ "<<t.first+1<<" , "<<t.second<<"]";
                    grid[t.first+1][t.second]=2;
                    fu.push({t.first+1,t.second});
                }
                if(t.first-1>=0&&grid[t.first-1][t.second]==1){
                    --hao;
                    grid[t.first-1][t.second]=2;
                    fu.push({t.first-1,t.second});
                    //std::cout<<"[ "<<t.first-1<<" , "<<t.second<<"]";
                }
                if(t.second+1<num_col&&grid[t.first][t.second+1]==1){
                    --hao;
                    grid[t.first][t.second+1]=2;
                    fu.push({t.first,t.second+1});
                    //std::cout<<"[ "<<t.first<<" , "<<t.second+1<<"]";
                }
                if(t.second-1>=0&&grid[t.first][t.second-1]==1){
                    --hao;
                    grid[t.first][t.second-1]=2;
                    fu.push({t.first,t.second-1});
                    //std::cout<<"[ "<<t.first<<" , "<<t.second-1<<"]\n";
                }
                --count;
            }
        }
        return hao>0?-1:mins;

    }
};
```
