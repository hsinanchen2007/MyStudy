```
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int x_size=matrix.size();
        if(x_size==0){
            vector<vector<int>> v;
            return v;
        }
        int y_size=matrix[0].size();
        vector<vector<int>> bp(x_size,vector<int>(y_size));
        queue<pair<int,int>> q;
        for(int i=0;i<x_size;++i){
            for(int j=0;j<y_size;++j){
                bp[i][j]=matrix[i][j]==0?0:-1;
                if(bp[i][j]==0)
                    q.push({i,j});
            }
        }
        vector<pair<int,int>> step={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;++i){
                pair<int,int> temp=q.front();
                q.pop();
                for(int j=0;j<4;++j){
                    int x=temp.first+step[j].first;
                    int y=temp.second+step[j].second;
                    if(x>=0&&x<x_size&&y>=0&&y<y_size&&bp[x][y]==-1){
                        bp[x][y]=bp[temp.first][temp.second]+1;
                        q.push({x,y});
                    }
                }
            }
        }
        return bp;
    }
};
```
