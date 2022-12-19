动态规划很简单
就是在动态规划的同时要记录之前的坐标
```
class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0){
            return obstacleGrid;
        }
        pair<int,int> p={-1,-1};
        int X=obstacleGrid.size();
        int Y=obstacleGrid[0].size();
        vector<vector<int>> ans;
        vector<vector<pair<int,int>>> bp(X,vector<pair<int,int>>(Y,{-1,-1}));
        if(obstacleGrid[0][0]==1){
            return ans;
        }
        bp[0][0]={-2,-2};
        for(int i=1;i<Y;++i){
            if(obstacleGrid[0][i]==1){
                continue;
            }
            if(bp[0][i-1]==p){
                bp[0][i]={-1,-1};
            }
            else{
                bp[0][i]={0,i-1};
            }
        }
        for(int i=1;i<X;++i){
            if(obstacleGrid[i][0]==1){
                continue;
            }
            if(bp[i-1][0]==p){
                bp[i][0]={-1,-1};
            }
            else{
                bp[i][0]={i-1,0};
            }
        }
        for(int i=1;i<X;++i){
            for(int j=1;j<Y;++j){
                if(obstacleGrid[i][j]==1||(bp[i-1][j]==p&&bp[i][j-1]==p)){
                    continue;
                }
                if(bp[i-1][j]==p){
                    bp[i][j]={i,j-1};
                }else{
                    bp[i][j]={i-1,j};
                }
            }
        }
        if(bp[X-1][Y-1]==p){
            return ans;
        }
        int first=X-1,second=Y-1;
        while(first!=-2&&second!=-2){
            //cout<<first<<" "<<second<<endl;
            ans.push_back({first,second});
            pair<int,int> temp=bp[first][second];
            first=temp.first;
            second=temp.second;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```
