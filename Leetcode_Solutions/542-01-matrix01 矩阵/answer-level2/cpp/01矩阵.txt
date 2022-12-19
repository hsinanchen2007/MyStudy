利用bfs进行求解，先找到所有0元素的位置，然后更新所有1位置的距离，更新完毕后获得的值即为每个1距离0最近的距离。
```
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int> > dirs={{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int> > que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0) que.push(make_pair(i,j));
                else matrix[i][j]=INT_MAX;
            }
        }
        while(!que.empty()){
            auto t=que.front();
            que.pop();
            for(auto dir:dirs){
                int x=t.first+dir[0],y=t.second+dir[1];
                if(x<0 || y<0 || x>=m || y>=n || matrix[x][y]<=matrix[t.first][t.second]+1) continue;
                matrix[x][y]=matrix[t.first][t.second]+1;
                que.push(make_pair(x,y));
            }
        }
        return matrix;
    }
};
```
