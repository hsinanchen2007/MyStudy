### 解题思路
1.海洋到陆地的距离与其相邻的四个点到海洋的距离有关：动态规划

2.从每个陆地出发每次更新其四周的点到陆地的距离：多源BFS

### 代码

```cpp
动态规划：
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        //judge whether all the elements are the same or not;
        if (count(grid.begin(), grid.end(), vector<int>(col, 0)) == row)
            return -1;
        if (count(grid.begin(), grid.end(), vector<int>(col, 1)) == row)
            return -1;
        vector<vector<int>> dis(row, vector<int>(col, INT_MAX-1));
        //left-up to right-down
        for (int i = 0; i < row; i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1)dis[i][j]=0;
                else{
                    if(i-1>=0&&dis[i-1][j]+1<dis[i][j])dis[i][j]=dis[i-1][j]+1;
                    if(j-1>=0&&dis[i][j-1]+1<dis[i][j])dis[i][j]=dis[i][j-1]+1;
                    if(dis[i][j]==row+col-2)return row+col-2;//达到可能的最大值直接返回；
                }
            }
        }
        //right-down to left-up
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                if(i+1<row&&dis[i+1][j]+1<dis[i][j])dis[i][j]=dis[i+1][j]+1;
                if(j+1<col&&dis[i][j+1]+1<dis[i][j])dis[i][j]=dis[i][j+1]+1;
                if(dis[i][j]==row+col-2)return row+col-2;//达到可能的最大值直接返回；
            }
        }

        int max=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(dis[i][j]>max)max=dis[i][j];
            }
        }
        return max;

    }
};

//多源BFS
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        //judge whether all the elements are the same or not;
        if (count(grid.begin(), grid.end(), vector<int>(col, 0)) == row)
            return -1;
        if (count(grid.begin(), grid.end(), vector<int>(col, 1)) == row)
            return -1;
        vector<vector<int>> dis(row, vector<int>(col, INT_MAX-1));
        queue<pair<int,int>>q;
        //put all the points which have a value of 1 into the queue;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    q.push(make_pair(i,j));
                    dis[i][j]=0;
                }
            }
        }
        int offset[][2]={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            pair<int,int>temp=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x=temp.first+offset[i][0];
                int y=temp.second+offset[i][1];
                if(x>=0&&x<row&&y>=0&&y<col){
                    if(dis[x][y]>dis[temp.first][temp.second]+1){
                        dis[x][y]=dis[temp.first][temp.second]+1;
                        //dis[x][y]<=dis[temp.first][temp.second]+1即说明该点入栈过
                        q.push(make_pair(x,y));
                    }
                }
            }
        }
        int max=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(dis[i][j]>max)max=dis[i][j];
            }
        }
        return max;
    }
};

```