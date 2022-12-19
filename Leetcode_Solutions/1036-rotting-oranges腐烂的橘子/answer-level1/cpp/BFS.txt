```
class Solution {
public:
    struct point{
        int x;
        int y;
    };
    int orangesRotting(vector<vector<int>>& grid) {
        queue<point>q;
        int good=0;
        int cnt=0;
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push(point{i,j});
                    cnt++;
                }else if(grid[i][j]==1){
                    good++;
                }
            }
        }
        int xP[]={1,0,-1,0};
        int yP[]={0,1,0,-1};
        int temp=0;
        while(!q.empty()){
            if(cnt==0){
                ans++;
                cnt=temp;
                temp=0;
            }
            point t=q.front();
            q.pop();
            cnt--;
            for(int i=0;i<4;i++){
                if(t.x+xP[i]>=0&&t.x+xP[i]<grid.size()&&t.y+yP[i]>=0&&t.y+yP[i]<grid[0].size()){
                    if(grid[t.x+xP[i]][t.y+yP[i]]==1){
                        q.push(point{t.x+xP[i],t.y+yP[i]});
                        grid[t.x+xP[i]][t.y+yP[i]]=2;
                        temp++;
                        good--;
                    }
                }
            }
        }
        if(good==0){
            return ans;
        }else{
            return -1;
        }
    }
};
```
