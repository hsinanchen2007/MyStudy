

```
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int high=grid.size();
        int width=grid[0].size();
        vector<vector<int>> v;
        vector<vector<int>> e;
        int ret=0;
        for(int i=0;i<high;i++){
            for(int j=0;j<width;j++){
                if(grid[i][j]==1){
                    v.push_back({i,j});
                }
            }
        }
        //cout<<v.size()<<endl;
        while(1){
            e.clear();
            for(auto a : v){
                int x=a[0],y=a[1];
                if((x-1>-1&&grid[x-1][y]==2)||(y-1>-1&&grid[x][y-1]==2)||(x+1<high&&grid[x+1][y]==2)||(y+1<width&&grid[x][y+1]==2)){
                    e.push_back(a);
                }
            }
            if(e.empty()) break;
            else ret++;

            for(auto a : e){
                //cout<<a[0]<<' '<<a[1]<<endl;
                grid[a[0]][a[1]]=2;
                v.erase(find(v.begin(),v.end(),a));
            }
            //cout<<v.size()<<endl;
        }
        if(v.empty()) return ret;
        else return -1;
    }
};

```
