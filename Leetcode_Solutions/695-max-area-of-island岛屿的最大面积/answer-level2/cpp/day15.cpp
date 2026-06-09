### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0)  
                    continue;
                stack<pair<int,int>> s;
                s.push({i,j});
                grid[i][j]=0;
                int ans=0;
                int di[4]={-1,0,0,1};
                int dj[4]={0,-1,1,0};
                while(!s.empty()){
                    int cur_i=s.top().first;
                    int cur_j=s.top().second;
                    //cout<<cur_i<<" "<<cur_j<<endl;
                    s.pop();
                    ans++;
                    for(int k=0;k<4;k++){
                        if(cur_i+di[k]<0 || cur_i+di[k]>=grid.size() || cur_j+dj[k]<0 ||cur_j+dj[k]>=grid[0].size() )
                            continue;
                        if(grid[cur_i+di[k]][cur_j+dj[k]]==1){
                            s.push({cur_i+di[k],cur_j+dj[k]});
                            grid[cur_i+di[k]][cur_j+dj[k]]=0;
                        }
                    }

                }
                max_=max(ans,max_);
            }
        return max_;
    }
};
```