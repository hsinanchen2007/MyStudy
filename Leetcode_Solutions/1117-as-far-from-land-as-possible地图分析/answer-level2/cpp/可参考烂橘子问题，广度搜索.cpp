和烂橘子问题基本一样，那个问题求多少天全部腐烂和这里曼哈顿距离一样。
```
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        set<pair<int,int>> ocean;
        vector<pair<int,int>> land;
        vector<pair<int,int>> tmp;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]) land.push_back({i,j});
                else ocean.insert({i,j});
            }
        }
        if(land.empty()||ocean.empty()) return -1;
        int dirx[4]={1,0,-1,0};
        int diry[4]={0,1,0,-1};
        pair<int,int > tmp2;
        int res=0;
        while(!ocean.empty()){
            for(auto pos:land){
                for(int i=0;i<4;++i){
                    tmp2=make_pair(pos.first+dirx[i],pos.second+diry[i]);
                    if(ocean.find(tmp2)!=ocean.end()) {
                        ocean.erase(tmp2);
                        tmp.push_back(tmp2);
                    }
                }
            }
            ++res;
            land=tmp;
            tmp.clear();
        }
        return res;
    }
};
```
